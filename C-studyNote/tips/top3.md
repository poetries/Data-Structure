这节涉及到处理工具，如命令行选项，文件读写，操纵信息流，重定向等，具体知识点如下：

- 模块化，一个函数只完成一件事，一个小工具
- 标准输入，标准输出，重定向
- 命令行选项

# 一.标准输入,标准输出，重定向
在第二节学习了<a href="https://github.com/BeginMan/BookNotes/blob/master/C/Top2:存储器和指针:指向何方.md">scanf,fgets函数</a>, 用于指针输入数据，下面展示一个例子

    int main(int argc, char <em>argv[]) {
        char name[30];
        int age=0;
        printf("请输入姓名和年龄：\n");

        // scanf返回成功读取的数据条数
    //    int a = scanf("%s%d", name, &age);
    //    printf("%d\n", a);
    //    printf("%s,%d\n", name, age);

        while (scanf("%s%d", name, &age) == 2) {
            printf("name:%s, age:%d\n", name, age);
        }

        return 0;
    }

在scanf语句的格式串中由于没有非格式字符,因此在输入时要用一个以上的空格或回车键作为每两个输入数之间的间隔。

<strong>上面例子中在用scanf()从键􏸏读取数据、printf()向显示器写数据时,这个输入源也可以是其他，如文件，这个输出源也可以是文件。</strong>,也就是下面的重定向

# 二.重定向

## 1.freopen

语法如下：

    FILE </em>freopen(const char <em>filename, const char </em>mode, FILE <em>stream)

这个函数用来重定向输出的，如下例子：

    int main(int argc, char </em>argv[]) {
        FILE <em>stream;
        printf("One\n");
        stream = freopen("out.txt", "a+", stdout);
        printf("Two\n");

        return 0;
    }

运行之后打印One, 将Two追加到out.txt文件中，具体可见:<a href="http://www.tutorialspoint.com/c_standard_library/c_function_freopen.htm">C library function - freopen()</a>

## 2.管道符

- <code>&gt;</code>: 重定向标准输出
- <code>&gt;&gt;</code>: 重定向输出，与<code>&gt;</code>不同的是它追加内容，而<code>&gt;</code>会清空内容后在写入
- <code>&lt;</code>: 重定向标准输入
- <code>&gt;&amp;</code>: 将一个句柄的输出写入到另一个句柄的输入中。
- <code>&lt;&amp;</code>: 从一个句柄读取输入并将其写入到另一个句柄输出中
- <code>|</code>: 管道，连接一个进程的标准输出与另一个进程的标准输入(一个程序的输出转向另一个程序的输入)

下面简单的程序：

    int main(int argc, char </em>argv[]) {
        char name[20];
        while (scanf("%19s", name) == 1) {
            printf("name:%s\n", name);
        }
        return 0;
    }


有一个含有名字的文件 names.txt,内容如下：

    Hello world
    C/C++
    Python
    Java
    JS
    Objective-C

那么我们用<code>&lt;</code>重定向输入：将names.txt文件作为输入源:

    ./main < names.txt
    name:Hello
    name:world
    name:C/C++
    name:Python
    name:Java
    name:JS
    name:Objective-C

这里为什么world另起一行呢，原因就是<strong>在scanf语句的格式串中由于没有非格式字符,因此在输入时要用一个以上的空格或回车键作为每两个输入数之间的间隔。</strong>

用<code>&gt;</code>重定向输出到out.txt文件中：

    ./main < names.txt > out.txt
    ./main < names.txt >> out.txt  // 追加

<img src="http://img.ddvip.com/2013_0912/16291378923988.jpg" alt="">

把stdout和stderr信息打印在一块：

    ./main < names.txt > out.txt 1>&2


## 3.fprintf() sends formatted output to a stream.

发送格式输出到数据流， 语法如下：

    int fprintf(FILE <em>stream, const char </em>format, ...)

- stream: FILE object指针，标识该数据流的文件对象
- format: 格式化字符串：<code>%[flags][width][.precision][length]specifier</code>

如：

    fprintf(stderr, "err");        // 标准错误输出
    fprintf(stdout, "good");    // 标准输出

一个简单的例子：

    #include <stdio.h>
    #include <stdlib.h>

    // 读取文件
    void readFile() {
        FILE <em> fp;
        char c;
        fp = fopen("file.txt", "r");
        while (1) {
            c = fgetc(fp);      // 读取一行
            if (feof(fp)) {     // EOF: 文件结尾
                break;
            }
            printf("%c", c);
        }
        fclose(fp);

    }

    // 写入文件
    void writeFile() {
        FILE </em> fp;                      // 声明一个 FILE类型的指针
        fp = fopen("file.txt", "w+");   // 以追加的方式打开文件
        // 格式化输出到文件流中
        fprintf(fp, "%s %s %s %d\n", "We", "are", "in", 2015);
        fprintf(stdout, "ok\n");

        // 一个进程最多有256个数据流，数据流有限，用完之后要关闭
        fclose(fp);
    }

    int main(int argc, char <em>argv[]) {
        writeFile();
        readFile();
        return 0;
    }

到目前为止，用了<code>printf</code>,<code>fprintf</code>,<code>sprintf</code>, 它三者区别如下：

- <code>printf</code> outputs to the standard output stream (<code>stdout</code>)
- <code>fprintf</code> goes to a file handle (`FILE</em><code>)
-</code>sprintf<code>goes to a buffer you allocated. (</code>char<em><code>)

参考:[Difference between fprintf, printf and sprintf?](http://stackoverflow.com/questions/4627330/difference-between-fprintf-printf-and-sprintf)

# 三.命令行选项
命令行选项用到</code>getopt()<code>函数，需要</code>unistd.h`头文件，getopt()函数的原型为：

    getopt(int argc,char </em>const argv[],const char <em>optstring)

这个函数要配合main函数使用，<strong>argc和argv一般就将main函数的那两个参数原样传入。</strong>

如下例子：


    # include <unistd.h>

    int main(int argc, char </em>argv[]) {<br>        int ch;        // 用于接收命令行选项的字符
        opterr=0;    // 全局变量 opterr=0 用于隐藏错误
        while ((ch = getopt(argc, argv, "a:b::cde")) != EOF) {        // 或 != -1
            printf("optind:%d\n", optind);
            printf("optarg:%s\n", optarg);
            printf("ch:%c\n\n", ch);

            switch (ch) {
                case 'a':
                    printf("option a:'%s'\n\n", optarg);
                    break;
                case 'b':
                    printf("option b:'%s'\n\n", optarg);
                    break;
                case 'c':
                    printf("option c\n\n");
                    break;
                case 'd':
                    printf("option d\n\n");
                    break;
                case 'e':
                    printf("option e\n\n");
                    break;
                default:
                    printf("other option\n\n");
                    break;
            }
        }
        printf("optopt + %c\n", optopt);

        // optind 保存了getopt()函数从命令行读取了几个选项
        // 跳过已读取的选项
        argc -= optind;
        argv += optind;     // 偏移量(指针运算符，数组首地址)

        return 0;
    }


gcc 编译后运行：

    ./main -a1234 -b567 -c -d -f

输出：

    optind:2
    optarg:1234
    ch:a

    option a:'1234'

    optind:3
    optarg:567
    ch:b

    option b:'567'

    optind:4
    optarg:(null)
    ch:c

    option c

    optind:5
    optarg:(null)
    ch:d

    option d

    optind:6
    optarg:(null)
    ch:?

    other option

    optopt + f

main函数总共接收了6个参数：

    argc=6;
    argv[0]=./main       // 程序自身
    argv[1]=-a1234<br>    argv[2]=-b567
    argv[3]=-c
    argv[4]=-d
    argv[5]=-f


- <code>optstring</code>是一段自己规定的选项串，例如本例中的<code>&quot;a:b::cde&quot;</code>,表示可以有，<code>-a</code>,<code>-b</code>,<code>-c</code>,<code>-d</code>,<code>-e</code>这几个参数。
- <code>“:”</code>:表示必须该选项带有额外的参数，全域变量<code>optarg</code>会指向此额外参数;
- <code>“::”</code>:标识该额外的参数可选(有些Uinx可能不支持<code>“::”</code>）。
- <code>optind</code>:全域变量指示下一个要读取的参数在<code>argv</code>中的位置,在argv中第几个.
- <code>opterr</code>:如果<code>getopt()</code>找不到符合的参数则会印出错信息，并将全域变量optopt设为<code>“?”</code>字符。如果不希望getopt()印出错信息，则只要将全域变量opterr设为0即可。


参考:<a href="http://zhangxuming.blog.51cto.com/1762/126785">关于C语言中getopt()函数的使用方法</a>



