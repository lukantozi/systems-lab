bool eq = (a && b) || (!a && !b);

# Write an HCL expression for a signal xor, equal to the exclusive-or of inputs a
# and b. What is the relation between the signals xor and eq defined above?

bool xor = (!a && b) || (a && !b);

# when eq is 1 xor will be 0 and vice versa
