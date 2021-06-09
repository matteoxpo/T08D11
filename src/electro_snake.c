/*
    1 6 7
    2 5 8
    3 4 9
*/
void sort_vertical(int **matrix, int n, int m);

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int n, int m);

/*
    7 8 9
    6 1 2
    5 4 3
*/
void sort_spiral(int **matrix, int n, int m);

void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);


void main()
{
    int **matrix;
    int n,m;

    input(matrix);
    
    sort_vertical(matrix, n, m);
    output(matrix);
    
    sort_horizontal(matrix, n, m);
    output(matrix);
    
    sort_spiral(matrix, n, m);
    output(matrix);

}
