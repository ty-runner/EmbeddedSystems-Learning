struct Employee
{
    int id;
    int age;
    double wage;
};

int main()
{
    Employee frank = { 1, 32, 60000.0 }; // copy-list initialization using braced list
    Employee joe = {2, 28, 45000.0 };     // list initialization using braced list (preferred)

    return 0;
}
