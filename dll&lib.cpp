//library

//dynamic static
//   .dll   .lib
//     .a
//dynamic动态库:程序不包含 
//static静态库:程序包含

//工程文件中添加这句话，把静态库包进来 
#pragma comment (lib, "testlib.lib") 
