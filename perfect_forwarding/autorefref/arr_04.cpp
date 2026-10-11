Nec {
        int a[5]{ 2, 3, 5, 7, 11 };
    };

    int* begin(Nec& x)
    {
        return x.a;
    }

    int* end(Nec& x)
    {
        return x.a + 5;
    }
}

int main()
{
    MyLib::Nec x;

    for (auto i : x) {
        std::cout << i << ' ';
    }
}
