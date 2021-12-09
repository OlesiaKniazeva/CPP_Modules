# include <iostream>

int main(int argc, char **argv)
{
    int i;
    int g;

    i = 1;
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        while (argv[i])
        {
            g = 0;
            while (argv[i][g])
            {
                std::cout << (char)toupper(argv[i][g]);
                g++;
            }
            if (argv[i + 1])
                std::cout << " ";
            else
                std::cout << std::endl;
            i++;
        }
    }
}