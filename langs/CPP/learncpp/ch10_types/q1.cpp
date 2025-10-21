int main()
{
    int a { 5 }; // 1a - No conversion
    int b { 'a' }; // 1b - promotion
    int c { 5.4 }; // 1c - compilation error, double -> int NONO
    int d { true }; // 1d - promotion -> 1
    int e { static_cast<int>(5.4) }; // 1e - narrow to 5

    double f { 5.0f }; // 1f - promotion, float -> double
    double g { 5 }; // 1g - conversion, int -> double

    // Extra credit section
    long h { 5 }; // 1h - conversion

    float i { f }; // 1i (uses previously defined variable f) - narrowing compilation, double -> float
    float j { 5.0 }; // 1j - conversion since 5.0  is a constexpr

}
