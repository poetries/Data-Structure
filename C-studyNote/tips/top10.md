
![](http://ww2.sinaimg.cn/mw690/6941baebgw1erejj2lwq9j20sg0ipdin.jpg)

# 一. 服务器连接网络四部曲
服务器连接网络，C程序用**数据流**读写字节， 这里用到了新的数据流：**套接字**。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top11_1.png)

在使用套接字与客户端程序通信前,服务器需要􏺚经四个阶段（**首字􏼌缩写为BLAB**）:

- 绑定(Bind)
- 监听(Listen)
- 接受(Accept)
- 开始(Begin)

## 1.1 绑定端口
绑定端口需要**套接字描述符**和**套接字名**， 如绑定一个30000端口


	#include <stdio.h>
	#include <errno.h>
	#include <string.h>
	#include <sys/socket.h>
	#include <arpa/inet.h>				// 绑定端口需要这个头

	void error(char *msg) {
	    fprintf(stderr, "%s,%s", msg, strerror(errno));
	    exit(1);
	}

	int main(){
	    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
	    if (listener_d == -1) { // 无法打开套接字
	        error("无法打开套接字");
	    }
	    
	    //绑定端口
	    struct sockaddr_in name;
	    name.sin_family = PF_INET;
	    name.sin_port = (in_port_t)htons(30000);
	    name.sin_addr.s_addr = htonl(INADDR_ANY);
	    int c = bind(listener_d, (struct sockaddr *) &name, sizeof(name));
	    if (c == -1) {
	        error("无法绑定端口");
	    }
	    
	    return 0;
	}

## 1.2 监听

	//监听
    if(listen(listener_d, 10) == -1)        // 队列长度为10
        error("无法监听");

>调用`listen()`把队列长度设为10,也就是说最多可以有10个 客户端同时尝试连接服务器,它们不会立即得到响应,但可以排队等待,而第11个客户端会被告知服务器太忙。

## 1.3 接受连接
>一旦􏾑定完端口,设置完􏾒听队列,唯一可以做的就是*等待*。服务器一生都在等待有客户端来连接它们。`accept()`系统调用会一直等待,直到有客户端连接服务器时,它会返回第二个 套接字描述符,然后就可以用它通信了。

	//接受连接
    struct sockaddr_storage client_addr;    // client_addr保存连接客户端的详细信息
    unsigned int address_size = sizeof(client_addr);
    int connect_id = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
    if (connect_id == -1) {
        error("无法打开副套接字");
    }

服务器将用新的**连接描述符**connect_id进行通信

## 1.4 开始send
>到目前为止,你见过的数据流都一样,不管是连接文件的数据流,还是连接标准输入或输出的数据流,都可以用`fprintf()`和`fscanf()`与它们通信。**但套接字有一点点不 同,套接字是双向的,它既可以用作输入也可以用作输出, 也就是说要用其他函数和它通信。如果想向套接字输出数据,就要用`send()`函数,而不是 fprintf()。**

	//send
    char *msg = "Internet Knock-Knock Protocol Server\r\nVersion 1.0\r\nKnock! Knock!\r\n> ";
    if (send(connect_id, msg, strlen(msg), 0) == -1) {
        error("无法send");
    }


## 1.5 注意：端口延迟

>当你在某个端口􏾑定了套接字,在接下来的30􏽑内,操作系统不􏶫许任何程序再􏾑定它,包括上一次􏾑定这个端口的程序。只要在􏾑定前设置套接字的某个选项就可以解决这个问题。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top11_2.png)
 
## 1.6 实例
 下面的例子客户端连接服务器后会收到随机发送的几句话：


	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <errno.h>
	#include <string.h>
	#include <sys/socket.h>
	#include <arpa/inet.h>

	void error(char *msg) {
	    fprintf(stderr, "%s,%s", msg, strerror(errno));
	    exit(1);
	}


	int main(){
	    char *advice[] = {
	        "测试\n",
	        "套接字处理\n",
	        "模拟100w并发测试\n",
	        "沉住气，稳住心，好好的学习Unix\n",
	        "多看书，多读经典书籍，多总结，多思考，多反复练习，多温故知新\n"
	    };
	    int listener_d = socket(AF_INET, SOCK_STREAM, 0);
	    if (listener_d == -1) {
	        error("无法打开套接字");
	    }
	    // 端口绑定有延迟
	    int reuse = 1;              // 需要一个整型变量来保存选项，设为1，表示重新使用端口
	    if (setsockopt(listener_d, SOL_SOCKET, SO_REUSEPORT, (char *)&reuse, sizeof(int)) == -1) {
	        error("无法设置套接字的“重新使用端口”选项");
	    }
	    // 绑定端口
	    struct sockaddr_in name;
	    name.sin_family = PF_INET;
	    name.sin_port = (in_port_t)htons(30000);
	    name.sin_addr.s_addr = htonl(INADDR_ANY);
	    int c = bind(listener_d, (struct sockaddr *)&name, sizeof(name));
	    if (c == -1) {
	        error("无法绑定端口");
	    }
	    
	    // 监听
	    if (listen(listener_d, 10) == -1) {     //队列长度10
	        error("无法监听");
	    }
	    puts("Waiting for connection...");
	    
	    while (1) {
	        //循环接受连接
	        struct sockaddr_storage client_addr;                // client_addr保存连接客户端的详细信息
	        unsigned int address_size = sizeof(client_addr);
	        int connect_id = accept(listener_d, (struct sockaddr *)&client_addr, &address_size);
	        if (connect_id == -1) {
	            error("无法打开副套接字");
	        }
	        //向客户端发送消息
	        char *msg = advice[rand() % 5];
	        if (send(connect_id, msg, strlen(msg), 0) == -1) {
	            error("无法send");
	        }
	        //关闭连接
	        close(connect_id);
	        
	    }
	    
	    return 0;
	}

启动服务器：

	➜  intoC git:(master) ✗ ./net2
	Waiting for connection...

客户端连接测试：

	➜  ylx git:(master) ✗ telnet 127.0.0.1 30000
	Trying 127.0.0.1...
	Connected to localhost.
	Escape character is '^]'.
	模拟100w并发测试
	Connection closed by foreign host.
	➜  ylx git:(master) ✗ telnet 127.0.0.1 30000
	Trying 127.0.0.1...
	Connected to localhost.
	Escape character is '^]'.
	多看书，多读经典书籍，多总结，多思考，多反复练习，多温故知新
	Connection closed by foreign host.



## 1.7 题外话：Linux端口的总结

- 端口范围0-65535（端口为16进制，那么2的16次方值为65536）
- 小于1024的端口往往是系统端口，如sshd(22)只有root或管理员才有权使用
- 大于1024的通常让我们来用
- Linux对外连接端口数有限制，默认不超过28232个连接， 执行`cat /proc/sys/net/ipv4/ip_local_port_range`查看， 61000-32768=28232个端口可以使用，单个IP对外只能发送28232个TCP请求。
- 突破限制的方法：把端口的范围区间增到最大，`echo "net.ipv4.ip_local_port_range = 1024 65000" >> /etc/sysctl.conf; sysctl -p`， 一个client可以发起65000个连接了。

# 二.客户端读取
套接字用`send()`写数据，用`recv()`读数据：

	<读了几个字节> = recv(<描述符>, <缓冲区>, <要读取几个字节>, 0);

## 2.1 recv()函数

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/top11_3.png)

`revc()`用起来十分繁琐,最好把它􏼢装在某个函数中,比如下面这个函数,它在指定数组中保存以\0结􏱴的字符串。

	#include <stdio.h>
	#include <errno.h>
	#include <string.h>
	#include <sys/socket.h>
	#include <arpa/inet.h>

	/**************************************************************************************/
	/*函数名称：int read_in(int socket, char *buf, int len)                                 */
	/*函数功能：recv读取封装函数                                                            */
	/*参数：   socket: 套接字描述符                                                    */
	/*        buf:    缓冲区     
	/*        len:    读取的字节数                                                        */
	/*返回值： len-slen                                                                       */
	/**************************************************************************************/
	int read_in(int socket, char *buf, int len) {       // 读取\n前所有字符
	    char *s = buf;
	    int slen = len;
	    int c = recv(socket, s, slen, 0);
	    while ((c > 0) && (s[c-1] != '\n')) {           // 循环读取字节直到没有字节可读或者读到\n
	        s += c;
	        slen -= c;
	        c = recv(socket, s, slen, 0);
	    }
	    if (c < 0) {
	        return c;       //防止错误
	    } else if (c == 0)
	        buf[0] = '\0';  // 什么都没有读到返回一个空字符串
	    else
	        s[c-1] = '\0';  // 用\0替换\r
	    return len-slen;
	}

# 三.􏵞􏷑动手写网络客户端
客户端和服务器使用套接字通信,但两者获取套接字的方式不同:

- 服务端：BLAB
- 客户端：只需两步，1.连接远程端口，2.开始通信

## 3.1 创建IP地址套接字
**在这之前务必学会`telnet`命令**

与服务器创建方式相同：

	int s = socket(PF_INET, SOCK_STREAM, 0);
    if (s == -1) {
        error("无法打开套接字");
    }

客户端和服务器处理套接字的方式不同,服务器会把套接字绑定到本地端口,而客户端会把套接字连接至远程端口:

	//连接远程端口
    struct sockaddr_in si;
    memset(&si, 0, sizeof(si));
    si.sin_family = PF_INET;
    si.sin_addr.s_addr = inet_addr("208.201.239.100");
    si.sin_port = htons(80);
    connect(s, (struct sockaddr *)&si, sizeof(si));

如果使用域名则使用`getaddrinfo()`函数:

	//创建DSN域名套接字
    struct addrinfo *res;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo("baidu.com", "80", &hints, &res);
    
`getaddrinfo()`在**堆**上创建了一个包含域名和端口的新的数据结构，那么接下来开始创建套接字：

	int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

然后再**远程连接套接字**, 并把堆上的名称资源用`freeaddrinfo()`函数干掉它：

	connect(s, res->ai_addr, res->ai_addrlen);
    freeaddrinfo(res);

 其中：`res->ai_addr`: 远程主机加端口的地址；`res->ai_addrlen`:地址存储器的长度.

 网络客户端实例：从维基百科下载某个页面的内容并在屏幕输出：


	#include <stdio.h>
	#include <string.h>
	#include <errno.h>
	#include <stdlib.h>
	#include <sys/socket.h>
	#include <arpa/inet.h>
	#include <unistd.h>
	#include <signal.h>
	#include <netdb.h>


	void error(char *msg)
	{
	    fprintf(stderr, "%s,%s", msg, strerror(errno));
	    exit(1);
	}

	int open_socket(char *host, char *port)
	{
	    struct addrinfo *res;
	    struct addrinfo hints;
	    memset(&hints, 0, sizeof(hints));
	    
	    hints.ai_family = PF_INET;
	    hints.ai_socktype = SOCK_STREAM;
	    if (getaddrinfo(host, port, &hints, &res)) {
	        error("Can't resolve the address");
	    }
	    
	    int d_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
	    if (d_sock == -1) {
	        error("Cant't open socket");
	    }
	    
	    int c = connect(d_sock, res->ai_addr, res->ai_addrlen);
	    freeaddrinfo(res);
	    if (c == -1) {
	        error("Cant't connect to socket");
	    }
	    
	    return d_sock;
	}

	int say(int socket, char *s)
	{
	    int result = send(socket, s, strlen(s), 0);
	    if (result == -1) {
	        fprintf(stderr, "%s:%s\n", "Error talking to the server", strerror(errno));
	    }
	    return result;
	}


	int main(int argc, char *argv[])
	{
	    int d_sock;
	    d_sock = open_socket("en.wikipedia.org", "80");
	    char buf[255];
	    
	    sprintf(buf, "GET /wiki/%s http/1.1\r\n", argv[1]);
	    say(d_sock, buf);
	    say(d_sock, "Host: en.wikipedia.org\r\n\r\n");          //向主机发送数据和空行
	    
	    char rec[256];
	    int bytesRcvd = recv(d_sock, rec, 255, 0);
	    while (bytesRcvd) {
	        if (bytesRcvd == -1) {
	            error("Can't read from server");
	        }
	        rec[bytesRcvd] = '\0';                      //在字符数组的末尾加\0使其成为字符串
	        printf("%s", rec);
	        bytesRcvd = recv(d_sock, rec, 255, 0);
	    }
	    close(d_sock);
	}

运行：

	gcc knock.c -o knock   
	./knock "O'Reilly_Media"
	 。。。

# 四.小结

- telnet是一个简易的网络客户端
- 服务器BALB四部曲
- 客户端两部曲
- `socket()`创建套接字
- `frok()`克隆子进程同时处理多个客户端

