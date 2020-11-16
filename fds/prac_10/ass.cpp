#include<iostream>

using namespace std;

void print(int **, int, int);

class matrix
{
    int rows, cols;
    int **mat, **sparseMat;
    int nonZero;
public:
    matrix()
    {
        rows = cols = nonZero = 0;
    }
    int doing_multiplication = 0;
    void inputMat()
    {
        cout<<"\n Enter the number of rows of the matrix : ";
        cin>>rows;
        cout<<" Enter the number of columns of matrix : ";
        cin>>cols;
        cout<<" Enter the elements of the matrix :\n";
        mat = new int*[rows];
      	for (int i = 0; i < rows; i++)
        {
        	mat[i] = new int[cols];
        	for (int j = 0; j < cols; j++)
            {
          		cin>> mat[i][j];
          		if (mat[i][j] != 0)
    				nonZero++;
    	    }
      	}
    }


    void convert_to_sparse_matrix()
    {
        sparseMat = new int*[nonZero+1];
    	for(int i = 0; i < nonZero + 1; i++)
    		sparseMat[i] = new int[3];
        sparseMat[0][0] = rows;
        sparseMat[0][1] = cols;
        sparseMat[0][2] = nonZero;

        int cnt = 1;
      	for (int i = 0; i < rows; i++)
        {
        	for (int j = 0; j < cols; j++)
            {
          		if (mat[i][j] != 0)
          		{
              		sparseMat[cnt][0] = i;
              		sparseMat[cnt][1] = j;
              		sparseMat[cnt][2] = mat[i][j];
              		++cnt;
          		}
        	}
      	}
      	print(sparseMat, nonZero + 1, 3);
    }


    void convert_to_original_matrix()
    {
        int r = sparseMat[0][0];
    	int c = sparseMat[0][1];
        int** m = new int *[r];

      	for (int i = 0; i < r; i++)
        {
        	m[i] = new int[c];
        	for(int j = 0; j < c; j++)
          		m[i][j] = 0;
      	}
        for(int i = 1; i < nonZero + 1; i++)
            m[ sparseMat[i][0] ][ sparseMat[i][1] ] = sparseMat[i][2];

        print(m, r, c);
    }


    void simple_transpose()
    {
        int** transpose =new int *[nonZero];
      	for (int i = 0; i <= nonZero; i++)
        	transpose[i] = new int[3];

    	transpose[0][0] = cols;
    	transpose[0][1] = rows;
    	transpose[0][2] = nonZero;

    	int cnt = 1;
    	for(int i = 0; i < cols; i++)
        {
        	for(int j = 1; j < nonZero+1; j++)
        	 {
          		if(sparseMat[j][1] == i)
          		{
            		transpose[cnt][0] = sparseMat[j][1];
            		transpose[cnt][1] = sparseMat[j][0];
            		transpose[cnt][2] = sparseMat[j][2];
            		cnt++;
          		}
        	}
      	}
        if(doing_multiplication == 1)
        {
            sparseMat = transpose;
            doing_multiplication = 0;
            return;
        }else
            print(transpose, nonZero + 1, 3);

      	delete[] transpose;
    }


    void fast_transpose()
    {
        int** t =new int *[nonZero];
      	for (int i = 0; i <= nonZero; i++)
        	t[i] = new int[3];
        t[0][0] = cols;
    	t[0][1] = rows;
    	t[0][2] = nonZero;

    	int cnt[cols];
        int updated_cnt[cols];
        for(int i=0;i<cols;i++)
        {
            cnt[i] = 0;
            updated_cnt[i] = 0;
        }

    	updated_cnt[0] = 1;

    	for(int i = 1; i <= nonZero; i++)
    	 	cnt[sparseMat[i][1]]++;

    	for(int i = 1; i < cols; i++)
         	updated_cnt[i] = cnt[i-1] + updated_cnt[i-1];

    	for(int i = 1; i <= nonZero; i++)
        {
         	int temp = updated_cnt[sparseMat[i][1]];
         	updated_cnt[sparseMat[i][1]]++;
         	t[temp][0] = sparseMat[i][1];
         	t[temp][1] = sparseMat[i][0];
         	t[temp][2] = sparseMat[i][2];
       	}

        print(t, nonZero + 1, 3);
        delete[] t;
    }


    void operator+(matrix &obj)
    {
        int ** addition = new int*[nonZero + obj.nonZero];
        for (int i = 0; i <= (nonZero + obj.nonZero); i++)
        	addition[i] = new int[3];

        addition[0][0] = rows;
        addition[0][1] = cols;
        addition[0][2] = 0;

        int itr1=1,itr2=1;
        int cnt = 1;
        while(itr1 <= nonZero || itr2 <= obj.nonZero)
        {
            if(sparseMat[itr1][0] < obj.sparseMat[itr2][0])
            {
                addition[cnt][0] = sparseMat[itr1][0];
                addition[cnt][1] = sparseMat[itr1][1];
                addition[cnt][2] = sparseMat[itr1][2];
                itr1++;
                cnt++;
            }
            else if(sparseMat[itr1][0] > obj.sparseMat[itr2][0])
            {
                addition[cnt][0] = obj.sparseMat[itr2][0];
                addition[cnt][1] = obj.sparseMat[itr2][1];
                addition[cnt][2] = obj.sparseMat[itr2][2];
                itr2++;
                cnt++;
            }
            else if(sparseMat[itr1][1] < obj.sparseMat[itr2][1])
            {
                addition[cnt][0] = sparseMat[itr1][0];
                addition[cnt][1] = sparseMat[itr1][1];
                addition[cnt][2] = sparseMat[itr1][2];
                itr1++;
                cnt++;
            }
            else if(sparseMat[itr1][1] > obj.sparseMat[itr2][1])
            {
                addition[cnt][0] = obj.sparseMat[itr2][0];
                addition[cnt][1] = obj.sparseMat[itr2][1];
                addition[cnt][2] = obj.sparseMat[itr2][2];
                itr2++;
                cnt++;
            }
            else
            {
                addition[cnt][0] = obj.sparseMat[itr2][0];
                addition[cnt][1] = obj.sparseMat[itr2][1];
                addition[cnt][2] = obj.sparseMat[itr2][2]+sparseMat[itr1][2];
                cnt++;
                itr1++;
                itr2++;
            }
        }
        while(itr1 <= nonZero)
        {
          addition[cnt][0] = sparseMat[itr1][0];
          addition[cnt][1] = sparseMat[itr1][1];
          addition[cnt][2] = sparseMat[itr1][2];
          itr1++;
          cnt++;
        }
        while(itr2 <= obj.nonZero)
        {
          addition[cnt][0] = obj.sparseMat[itr2][0];
          addition[cnt][1] = obj.sparseMat[itr2][1];
          addition[cnt][2] = obj.sparseMat[itr2][2];
          itr2++;
          cnt++;
        }

        addition[0][2] = cnt-1;

        print(addition, cnt, 3);
    }


    void operator*(matrix &obj)
    {

        int ** multiplication = new int *[50];
        for(int i = 0; i < (50); i++)
            multiplication[i] = new int[3];

        multiplication[0][0] = rows;
        multiplication[0][1] = obj.cols;
        multiplication[0][2] = 0;

        int temp[rows][obj.cols];
        doing_multiplication = 1;
        obj.simple_transpose();

        for(int i=0; i<rows; i++)
            for(int j=0; j<obj.cols; j++)
                temp[i][j]=0;

        for(int i=1;i<=nonZero; i++)
            for(int j=1; j<=obj.nonZero; j++)
                if(sparseMat[i][1] == obj.sparseMat[j][1])
                    temp[sparseMat[i][0]][obj.sparseMat[j][0]] += sparseMat[i][2] * obj.sparseMat[j][2];

        int cnt = 1;
        for(int i=0; i<rows; i++)
            for(int j=0; j<obj.cols; j++)
                if(temp[i][j]!=0)
                    {
                        multiplication[cnt][0] = i;
                        multiplication[cnt][1] = j;
                        multiplication[cnt][2] = temp[i][j];
                        cnt++;
                    }

        multiplication[0][2] = cnt - 1;
        print(multiplication, cnt, 3);

    }
    ~matrix()
    {
        delete[] mat;
        delete[] sparseMat;
    }

}mat1, mat2;

void print(int **m, int r, int c )
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
            cout<< m[i][j]<< " ";
        cout<<endl;
    }
}


int main()
{
    cout<<"\n Enter First Matrix : ";
    mat1.inputMat();
    cout<<"\n Enter Second Matrix : ";
    mat2.inputMat();
    char continue_or_not = 'Y';
    int choice;
    do{
        cout<<"\n 1. Normal to Sparse \t\t 2. Sparse to Normal"
            <<"\n 3. Simple Transpose \t\t 4. Fast Transpose"
            <<"\n 5. Addition of Matrices \t 6. Multiplication of Matrices ";
        cout<<"\n Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1: cout<<"\n The sparse Matrix for Matrix 1 is : \n";
                    mat1.convert_to_sparse_matrix();
                    cout<<"\n The sparse Matrix for Matrix 2 is : \n";
                    mat2.convert_to_sparse_matrix();
                    break;
            case 2: cout<<"\n The Original Matrix 1 is : \n";
                    mat1.convert_to_original_matrix();
                    cout<<"\n The Original Matrix 2 is : \n";
                    mat2.convert_to_original_matrix();
                    break;
            case 3: cout<<"\n The transpose of the Sparse Matrix 1(Simple Transpose) is : \n";
                    mat1.simple_transpose();
                    cout<<"\n The transpose of the Sparse Matrix 2(Simple Transpose) is : \n";
                    mat2.simple_transpose();
                    break;
            case 4: cout<<"\n The transpose of the Sparse Matrix 1(Fast Transpose) is : \n";
                    mat1.fast_transpose();
                    cout<<"\n The transpose of the Sparse Matrix 2(Fast Transpose) is : \n";
                    mat2.fast_transpose();
                    break;
            case 5: cout<<"\n The Addition of Sparse Matrix 1 and Sparse Matrix 2 results in : \n";
                    mat1 + mat2;
                    break;
            case 6: cout<<"\n The Multiplication of Sparse Matrix 1 and Sparse Matrix 2 results in :\n";
                    mat1 * mat2;
                    break;
            default:cout<<"\n Wrong Choice Entered !!! Enter Again !! \n";
                    continue;
        }
        cout<<"\n Want to continue?? ";
        cin>>continue_or_not;

    }while(continue_or_not == 'y'|| continue_or_not == 'Y');

    return 0;

}
