# CS:APP 3e, Problem 4.12: select the median of three inputs.

word Med3 = [
  B <= A && A <= C : A
  C <= A && A <= B : A
  A <= B && B <= C : B
  C <= B && B <= A : B
  1                : C
]
