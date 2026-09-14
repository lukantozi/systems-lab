# Write HCL code describing a circuit that for word inputs A, B, and C selects the
# median of the three values. That is, the output equals the word lying between the
# minimum and maximum of the three inputs.

word Med3 = [
  B <= A && A <= C : A
  C <= A && A <= B : A
  A <= B && B <= C : B
  C <= B && B <= A : B
  1                : C
]
