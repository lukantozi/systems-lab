word Min3 = [
        A <= B && A <= C : A;
        B <= A && B <= C : B;
        1                : C;
];

# The HCL code given for computing the minimum of three words contains four
# comparison expressions of the form X <= Y . Rewrite the code to compute the
# same result, but using only three comparisons.

word Min3_opt = [
        A <= B && A <= C : A;
        B <= C           : B;
        1                : C;
];
