/*
	Instruction

    In a small town the population is p0 = 1000 at the beginning of a year. The population regularly increases by 2 percent per year and moreover 50 new inhabitants per year come to live in the town. How many years does the town need to see its population greater or equal to p = 1200 inhabitants?

    At the end of the first year there will be:
    1000 + 1000 * 0.02 + 50 => 1070 inhabitants

    At the end of the 2nd year there will be:
    1070 + 1070 * 0.02 + 50 => 1141 inhabitants (number of inhabitants is an integer)

    At the end of the 3rd year there will be:
    1141 + 1141 * 0.02 + 50 => 1213

    It will need 3 entire years.
    More generally given parameters:

    p0, percent, aug (inhabitants coming or leaving each year), p (population to surpass)

    the function nb_year should return n number of entire years needed to get a population greater or equal to p.

    aug is an integer, percent a positive or null number, p0 and p are positive integers (> 0)

    Examples:
    nb_year(1500, 5, 100, 5000) -> 15
    nb_year(1500000, 2.5, 10000, 2000000) -> 10
    Note: Don't forget to convert the percent parameter as a percentage in the body of your function: if the parameter percent is 2 you have to convert it to 0.02.
*/

/*
	Sample Tests

    #include <stdio.h>
    #include <stdlib.h>
    #include <criterion/criterion.h>

    int nbYear(int p0, double percent, int aug, int p);

    void dotest(int p0, double percent, int aug, int p, int expr)
    {
        int act = nbYear(p0, percent, aug, p);
        if(act != expr)
            printf("Expected %d, got %d\n", expr, act);
        cr_assert_eq(act, expr, "");
    }

    Test(nbYear, ShouldPassAllTheTestsProvided) {
          dotest(1500, 5, 100, 5000,15);
          dotest(1500000, 2.5, 10000, 2000000, 10);
          dotest(1500000, 0.25, 1000, 2000000, 94);
    }
*/

int nbYear(int p0, double percent, int aug, int p) {
    int count = 0;
    double percent0 = percent / 100;

    while(p0 < p){
          p0 = p0 + p0 * percent0 + aug;
          count++;
    }

    return count;
}