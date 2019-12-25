class Fraction
{
    friend Fraction mult_fracs(const Fraction & lhs, const Fraction & rhs);

    private:
    float up;
    float down;
};