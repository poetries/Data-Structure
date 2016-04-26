这一章节主要学习：

- 函数指针的使用
- void指针的威力
- 创建函数指针数组
- 可变参数函数


# 一.函数指针

函数中传递函数名，**函数名是指向函数的指针**,当你创建`myfunc(int arg)`的函数也创建了`myfunc`的指针变量(this save address of function), 当调用函数时，你在使用函数指针
 
## 1.没有函数类型
 
在C中没有函数类型，so, 就不能用 `function *` 声明函数指针
 
    int *a;         // 声明 int指针
    function *f;    // error
 
## 2.如何创建函数指针

一个示例代码：
 
    int (*warp_fn)(int);        // 创建warp_fn变量，保存func1()函数的地址
    warp_fn = func1;
    warp_fn(4);                 // 相当于调用func1()
 
    char** (*name_fn)(char *, int); //name_fn变量保存函数地址
    name_fn = func2;
    char** results = name_fn("good", 19); 

这么复杂的原因：**函数返回类型，参数类型要告诉编译器**
 
`char**`: 是一个指针，通常用来指向字符串数组.

### 2.1 通常的函数调用

	void myfunc(int x); // 声明函数， 也可写成：void myfunc(int)

	int main(int argc, char *argv[]) {
	    myfunc(10);     // 函数调用
	    return 0;
	}

	void myfunc(int x) {    // 函数定义
	    printf("%i\n", x);
	}

### 2.2 函数指针变量的声明与调用
函数的首地址也以存储在某个函数指针变量里的,就可以通过这个函数指针变量来调用所指向的函数了.

	void (*funp)(int);  // 声明指向myfunc函数的函数指针变量funp

也可写：

	void (*funp)(int x);

关于调用形式，有好几种：

	void myfunc(int x); // 声明函数， 也可写成：void myfunc(int)
	void (*funp)(int);  // 声明指向myfunc函数的函数指针变量funp

	int main(int argc, char *argv[]) {
	    myfunc(10);         // 函数调用, 10
	    
	    funp = &myfunc;    // 将myfunc地址赋值给funp, 20
	    funp(20);
	    
	    funp = myfunc;      // myfunc赋值给funp, 30
	    funp(30);
	    
	    (*myfunc)(40);      // *myfunc取值, 40
	    
	    (*funp)(50);        // *funp取值, 50
	    
	    return 0;
	}

	void myfunc(int x) {    // 函数定义
	    printf("%i\n", x);
	}

通过这段代码我们可以得出以下结论：

- 1）其实，MyFun的函数名与FunP函数指针都是一样的，即都是函数指针。MyFun函数名是一个函数指针常量，而FunP是一个函数数指针变量，这是它们的关系。
- 2）但函数名调用如果都得如(*MyFun)(10)这样，那书写与读起来都是不方便和不习惯的。所以C语言的设计者们才会设计成又可允许MyFun(10)这种形式地调用（这样方便多了并与数学中的函数形式一样，不是吗？）。
- 3）为统一起见，FunP函数指针变量也可以FunP(10)的形式来调用。
- 4）赋值时，即可FunP = &MyFun形式，也可FunP = MyFun。

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/point_of_func.png)

### 2.3 定义函数指针类型

	typedef void (*FunType)(int);   // 定义一个函数指针类型
	FunType funp;                   // 用FunType类型声明全局变量funp

在`void (*FunType)(int)`前加了一个`typedef`。这样只是定义一个名为FunType函数指针类型，而不是一个FunType变量。

	void myfunc(int x);             // 声明函数， 也可写成：void myfunc(int)

	typedef void (*FunType)(int);   // 定义一个函数指针类型
	FunType funp;                   // 用FunType类型声明全局变量funp

	int main(int argc, char *argv[]) {
	    funp = myfunc;      // funp = &myfunc;
	    funp(100);
	    return 0;
	}

	void myfunc(int x) {    // 函数定义
	    printf("%i\n", x);
	}

有了FunType类型后，我们就可以同样地、很方便地用FunType类型来声明多个同类型的函数指针变量了。如下：

	FunType funp; 
	FunType funp2;
	...

# 二. void指针

**`(void*)x` 指针能够保存任意类型的指针, `void*` 虽然是任意类型的指针但是使用前一定要转换成指定类型的指针**

如下实例，比较数字大小，比较字符串：

	// void* 可以是任意类型的指针
	// 比较分数
	int compare_scores(const void* score_a, const void* score_b) {
	    // void* 虽然是任意类型的指针但是使用前一定要转换成指定类型的指针
	    // 从指针中提取值, (int*)score:把void指针->int指针， 第一个*取地址(int指针)里的值
	    int a = *(int*)score_a;
	    int b = *(int*)score_b;
	    return a-b;
	}

	//降序比较分数
	int compare_scores_desc(const void* score_a, const void* score_b) {
	    int a = *(int*)score_a;
	    int b = *(int*)score_b;
	    return b-a;
	    // 或者： return compare_scores(score_b, score_a);
	}

	typedef struct {
	    int width;
	    int height;
	} rectangle;

	//比较areas
	int compare_areas(const void* a, const void* b) {
	    // void*要转换成对应类型(rectangle)的指针
	    rectangle* la = (rectangle*)a;          // 声明rectangle类型的指针变量la,并赋值
	    rectangle* lb = (rectangle*)b;
	    int sa = (la->width * la->height);
	    int sb = (lb->width * lb->height);
	    return sa-sb;
	}

	//比较字符串,按字母序排列，区分大小写
	int compare_names(const void* a, const void* b) {
	    char** sa = (char**)a;      // 字符串是字符指针，所以得到指针的指针
	    char** sb = (char**)b;
	    return strcmp(*sa, *sb);    // *取得字符串, a,b的类型是 char**, 而strcmp需要比较的是char*类型的值
	}

	int main(int argc, char *argv[]) {
	    int scores[] = {543,323,32,554,11,3,112};
	    int i;
	    // qsort排序并更新
	    // scores:作用对象， 7:总数， sizeof(int):每项大小，compare_scores_desc比较函数
	    qsort(scores, 7, sizeof(int), compare_scores_desc);
	    puts("There are scores with order;");
	    for(i=0; i<7; i++) {
	        printf("%d\n", scores[i]);
	    }
	    
	    char *names[] = {"Jack", "Ben", "Bezay", "Zen"};
	    
	    // 字符串数组 names每一项都是字符指针(char *), 当qsort()函数比较时会发送两个指向数组元素的指针
	    // 也就是说比较器函数接收到的是指向字符指针的指针，也就是char**
	    
	    qsort(names, 4, sizeof(char*), compare_names); // sizeof(char *): 数组元素是字符串（字符指针数组），所以是 char*
	    puts("names:");
	    for(int i=0; i<4; i++){
	        printf("%s\n", names[i]);
	    }
	    return 0;
	}

**一定要看看哟~**


# 三. 创建函数指针数组

先从一个例子开始，下面的程序是女神对下面的屌丝们发信息,信息类型有(分手，第二次机会和结婚), 我们脑海里可能想起了`enum`设置三种类型， `struct`定义结构，分别定义三种函数进行操作。如下代码：

	enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

	typedef struct {
	    char *name;
	    enum response_type type;
	} response;

	void dump(response r){
	    printf("DUMP:%s\n", r.name);
	}

	void second_chance(response r) {
	    printf("SC:%s\n", r.name);
	}

	void marriage(response r) {
	    printf("Marriage:%s\n", r.name);
	}

	int main(int argc, char *argv[]) {
	    response r[] = {
	        {"Jack", DUMP},
	        {"Link", DUMP},
	        {"Lurcy", SECOND_CHANCE},
	        {"Rose", MARRIAGE}
	    };
	    for(int i=0; i<4; i++) {
	        if(r[i].type == DUMP) {
	            dump(r[i]);
	        } else if (r[i].type == SECOND_CHANCE) {
	            second_chance(r[i]);
	        } else {
	            marriage(r[i]);
	        }
	    }
	    return 0;
	}

从上面代码看出我们需不断if，调用不同的函数，一旦函数变多了，就有点麻烦了。此时就该**函数指针数组**发挥作用了。

如果再一个数组中保存函数名：

	replies[] = {dump, second_chance, marriage}

**这种做法行不通， 我们必须要告诉编译器它的返回类型，参数类型等， 有点像函数指针的声明**, 正确的写法如下：

	void(*replies[])(response) = {dump, second_chance, marriage}


![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/point_of_func_array.png)

我们发现枚举顺序与函数指针数组对应的顺序一样， 枚举中元素从0开始，也就是DUMP=0, SECOND_CHANCE=1..，

	enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};
	void(*replies[])(response) = {dump, second_chance, marriage}

可以通过`response_type`枚举来获取数组中函数指针：

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/point_of_func_array2.png)


	enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};

	typedef struct {
	    char *name;
	    enum response_type type;
	} response;

	void dump(response r){
	    printf("DUMP:%s\n", r.name);
	}

	void second_chance(response r) {
	    printf("SC:%s\n", r.name);
	}

	void marriage(response r) {
	    printf("Marriage:%s\n", r.name);
	}

	// 声明函数指针
	//void (*Ddump)(response);
	//void (*Ssecond_chance)(response);
	//void (*Mmarriage)(response);

	// 创建函数指针数组
	void (*funcs[])(response) = {dump, second_chance, marriage};

	int main(int argc, char *argv[]) {
	    response r[] = {
	        {"Jack", DUMP},
	        {"Link", DUMP},
	        {"Lurcy", SECOND_CHANCE},
	        {"Rose", MARRIAGE}
	    };
	    for(int i=0; i<4; i++) {
	        funcs[r[i].type](r[i]); // or: (funcs[r[i].type])(r[i])
	    }

	    return 0;
	}


来分解这个函数：

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/point_of_func_array3.png)

这样做的好处是：

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/point_of_func_array4.png)

# 四. 可变参数函数

我们在用python的时候，可以提供可变参数的形式：
	
	# python
    def task(self, jsonDatas, *args, **kwargs):
    	.....

因为Python是C写的，那么C也有可变参数，**参数数量可变的函数被成为：可变参数函数**

![](https://raw.githubusercontent.com/BeginMan/BookNotes/master/C/media/variablesfunc.png)

	#include <stdio.h>
	#include <stdarg.h>     # need it

	void print_ints(int args, ...) {
	    // args: 参数个数
	    va_list ap;             // va_list用来保存传给函数的其他参数。
	    va_start(ap, args);
	    
	    for(int i=0; i<args; i++) {
	        printf("argument:%i\n", va_arg(ap, int));   // va_arg 逐行读取va_list保存的其他参数，接收两个参数：va_list和参数类型
	    }
	    
	    va_end(ap);     // 当读完了所有参数,要用va_end宏告诉C你做完了
	}
	int main(int argc, char *argv[]) {
	    print_ints(4, 1, 2, 3, 4);
	    return 0;
	}

输出结果：

	argument:1
	argument:2
	argument:3
	argument:4




参考：

[C语言函数名与函数指针详解](http://c.biancheng.net/cpp/html/496.html) 



