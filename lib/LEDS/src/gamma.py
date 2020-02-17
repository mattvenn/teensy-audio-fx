## Creates a gamma-corrected lookup table
import math

def gamma(nsteps, gamma):
    gammaedUp = [math.pow(x, gamma) for x in range(nsteps)]
    return [x/max(gammaedUp) for x in gammaedUp]

def rounder(topValue, gammas):
    return [min(topValue, round(x*topValue)) for x in gammas]

if __name__ == "__main__":
    myGamma = 2.3
    steps = 2 ** 12
    max_val = steps - 1
    output = file("gamma.h", "w")
    output.write("/* %d-step brightness table: gamma = %s */ \n\n" % (steps, myGamma))
    output.write("const int gamma_table[%d] = {\n" % steps)
    for value in rounder(max_val, gamma(steps, myGamma)):
        output.write("\t %d,\n" % value)
    output.write("};\n")
    output.close()


