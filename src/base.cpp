#include <iostream>

int _add_()
{
    int x, y;
    std::cout << "input the value of x, y: " << std::endl;
    std::cin >> x >> y;
    std::cout << "the answer of x + y is: " << x + y << std::endl;
    return 0;
}

void __input_args__(int argc, char *argv[])
{
    std::cout << "共有 " << argc << " 个参数." << std::endl;
    for (int i = 0; i < argc; i++)
    {
        if (i == 0)
        {
            std::cout << "文件的绝对路径是: " << argv[i] << std::endl;
        }
        else
        {
            std::cout << "第 " << i << " 个输入参数是 " << argv[i] << std::endl;
        }
    }
}

int Hello()
{
    std::cout << "hello,world!" << std::endl;
    return 0;
}