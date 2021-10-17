#include <iostream>
#include <vector>
using namespace std;

#define ElementType int

void Print_Array ( vector<ElementType> &A, long int Number );//Prlong int the Array
void Swap( ElementType *A, ElementType *B );//Swap two elements of the Array

// Function of Sort
void Bubble_Sort ( vector<ElementType> &A, long int Number );//冒泡排序（从小到大）
void Insertion_Sort ( vector<ElementType> &A, long int Number );//插入排序（从小到大）
void Shell_Sort( vector<ElementType> &A, long int Number) ;//希尔排序（从小到大）
void Heap_Sort ( vector<ElementType> &A, long int Number );//堆排序:伪代码(未完)
void Merge_Sort ( vector<ElementType> &A, long int Number );//递归归并排序（从小到大）
void Merge_Sort2 ( vector<ElementType> &A, long int Number );//非递归归并排序（从小到大）
void Quick_Sort ( vector<ElementType> &A, long int Number );//快速排序（从小到大）

int main (void) {
    long int Number;
    //input Number elements of Data Array
    cin >> Number;
    if ( Number <= 0 || Number > 100000 ) {
        return 0;
    }
    vector<ElementType> A( Number + 1 ); //build a vector to save the Array
    for( long int i=0; i<Number; i++ ) {
        cin >> A[i];
    }
    if ( Number == 1 ) {
        cout << A[0];
    } else if ( Number < 100 ) {
        //Test some Sort Functions
        Insertion_Sort( A, Number );
        Print_Array ( A, Number );
    } else if ( Number <= 100000 ) {
        Merge_Sort2 ( A, Number );
        Print_Array ( A, Number );
    }
    A.clear();
    return 0;
}

//Prlong int the Array
void Print_Array ( vector<ElementType> &A, long int Number ) {
    cout << A[0];
    for ( long int i=1; i<Number; i++) {
        cout << " " << A[i];
    }
}

//Swap two elements of the Array
void Swap( ElementType *A, ElementType *B ) {
    ElementType temp;
    //三部曲
    temp = *A; // 存A
    *A = *B; //换A
    *B = temp; //换B
}
//冒泡排序（从小到大）
void Bubble_Sort ( vector<ElementType> &A, long int Number ) {
    bool isSwapedFlag;
    ElementType temp;
    for ( long int i = Number-1; i > 0; i--) {
        isSwapedFlag = false;
        for ( long int j = 0; j < i; j++) {
            // >:从小到大； <:从大到小
            if ( A[j] > A[j+1] ) {
                Swap( &A[j], &A[j+1] );
                /* dosen't work
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                */
                isSwapedFlag = true;
            }
        }
        if ( !isSwapedFlag ) break; //没有发生一次交换，说明已经有序，退出
    }
}

//插入排序（从小到大）
void Insertion_Sort ( vector<ElementType> &A, long int Number ) {
    ElementType temp;
    long int i;
    //认为A[0]已经插入了
    for ( long int P = 1; P < Number; P++ ) {
        temp = A[P];//取待插入排序元素到temp
        for ( i = P; i > 0 && A[i-1] > temp; i--) {
            //从后往前循环，大的元素往后挪，直到不小于temp处退出循环
            A[i] = A[i-1];
        }
        A[i] = temp;//此是i为不大于temp的下标，插入temp
    }
}

//希尔排序（从小到大）
void Shell_Sort( vector<ElementType> &A, long int Number) {
    ElementType temp;
    long int i;
    //Hibbard增量序列:Dk = 2^k - 1 (相邻元素互质)
    //猜想Hibbard时间复杂度: Tavg = O(N^1.25)、Tworst = O(N^1.5)

    //Sedgewick增量序列:{1,5,19,41,109,...}－－9x4^i - 9x2^i + 1 或　4^i - 3x2^i + 1
    //猜想Sedgewick时间复杂度: Tavg = O(N^1.167)、Tworst = O(N^1.33)

    //希尔原始增量序列D{Number/2、Number/4、...、1}　－－劣势：增量元素不互质，则小增量可能不起作用
    //猜想希尔原始增量序列时间复杂度: Tworst = O(N^2)
    for ( long int D = Number/2; D > 0; D /=2 ) {
        //每次循环按增量序列进行“插入排序”(视为将插入排序中的'1'换成'D')
        for ( long int p = D; p < Number; p++) {
            temp = A[p];
            for ( i = p; i>=D && A[i-D]>temp; i-=D ) {
                A[i] = A[i-D];
            }
            A[i] = temp;//此是i为不大于temp的下标，插入temp
        }
    }
}

//堆向下过滤子函数:tree_position－－当前堆根节点、Number－－当前堆元素个数
void PercDown( vector<ElementType> &A, long int tree_position, long int Number) {

}
//堆排序:伪代码(未完)
void Heap_Sort ( vector<ElementType> &A, long int Number ) {
    //建立最大堆
    for ( long int i = Number/2; i>=0; i-- ) {
        PercDown( A, i, Number );//调整成最大堆
    }

    for ( long int i = Number-1; i>0; i--) {
        Swap( &A[0], &A[i] );/*将最大值元素根节点，换到当前堆最后一个元素位置上去*/
        PercDown( A, 0, i );
    }
}
/**************************************************************************************************************************/
//子列归并：有序子列归并。将有序序列A[]的左、右两相邻的'某部分'序列合并成一个新的有序序列，存于TempA
//参数说明：A[]－－原始待排序列A;   TempA[]－－待添加于A[]的临时序列，L－－A[]待归并的起始下标；R－－右边待归并序列起始下标；Right_End－－右边待归并序列终止下标
//假定A[]序列终止下标，正好是TempA[]起始下标的前一位
void Merge ( vector<ElementType> &A, vector<ElementType> &TempA, long int L, long int R, long int Right_End ) {
    long int temp, LeftEnd, NumOfElements;
    LeftEnd = R - 1; /* 左边终点下标与右边起始下标相邻  */
    temp = L; /*存放结果的数组初始位置*/
    NumOfElements = Right_End - L + 1;
    // 开始比较大小　存放
    while ( (L <= LeftEnd) && (R <= Right_End) ) {
    /*左右两序列都非空时执行*/
        if( A[L] < A[R] ) {
            TempA[temp++] = A[L++];
        } else {
            TempA[temp++] = A[R++];
        }
    }
    //左右两序列其一为空,下方两while只会执行一个(将余下的所有元素拷贝到TempA[])
    while ( L <= LeftEnd ) {
        TempA[temp++] = A[L++];
    }
    while ( R <= Right_End ) {
        TempA[temp++] = A[R++];
    }
    //将归并后的有序子列TempA存于A[]原来的位置
    for ( long int i=NumOfElements; i>0; i--, Right_End-- ) {
        A[Right_End] = TempA[Right_End];
    }
}
//Merge2为前面Merge函数拷贝，但省去结尾将TempA[]拷贝回A[]的步骤
void Merge2 ( vector<ElementType> &A, vector<ElementType> &TempA, long int L, long int R, long int Right_End ) {
    long int temp, LeftEnd, NumOfElements;
    LeftEnd = R - 1; /* 左边终点下标与右边起始下标相邻  */
    temp = L; /*存放结果的数组初始位置*/
    NumOfElements = Right_End - L + 1;
    // 开始比较大小　存放
    while ( (L <= LeftEnd) && (R <= Right_End) ) {
    /*左右两序列都非空时执行*/
        if( A[L] < A[R] ) {
            TempA[temp++] = A[L++];
        } else {
            TempA[temp++] = A[R++];
        }
    }
    //左右两序列其一为空,下方两while只会执行一个(将余下的所有元素拷贝到TempA[])
    while ( L <= LeftEnd ) {
        TempA[temp++] = A[L++];
    }
    while ( R <= Right_End ) {
        TempA[temp++] = A[R++];
    }
}
//递归算法
void M_Sort( vector<ElementType> &A, vector<ElementType> &TempA, long int L, long int Right_End) {
    long int Center;
    //分而治之
    if ( L < Right_End ) {
        Center = ( L + Right_End ) / 2;
        M_Sort( A, TempA, L, Center); /*左半部分递归调用*/
        M_Sort( A, TempA, Center+1, Right_End); /*右半部分递归调用*/
        Merge( A, TempA, L, Center+1, Right_End );//调用归并排序
    }
}
//递归归并排序算法（统一接口）
void Merge_Sort ( vector<ElementType> &A, long int Number ) {
    vector<ElementType> TempA( Number );//build a Temp vector
    M_Sort( A, TempA, 0, Number-1 );
    TempA.clear();
}
//非递归算法
//length 相当于当前子列长度
void Merge_pass( vector<ElementType> &A, vector<ElementType> &TempA, long int Number, long int length ) {
    long int i;
    //Number - 2*length　————先处理数组长度内能被２整除的前部分，尾巴先不管
    for ( i=0; i <= Number - 2*length; i += 2*length ) {
        Merge2 ( A, TempA, i,  i+length, i + 2*length -1 );
    }
    //处理尾巴:
    //尾巴长度为　1.0~1.9 倍的length时[还剩2个子列]，归并((0~1)*length)、((1*length~末尾)两个子列
    if (i+length < Number) {
        Merge2 ( A, TempA, i, i+length, Number-1 );
    } else {
        //否则，只剩下不到一个子列，原样拷贝
        for ( long int j = i; j < Number; j++) {
            TempA[j] = A[j];
        }
    }
}
//非递归归并排序算法（统一接口）
void Merge_Sort2 ( vector<ElementType> &A, long int Number ) {
    long int length = 1;//初始化子序列长度
    vector<ElementType> TempA( Number );//build a Temp vector
    while ( length < Number ) {
        Merge_pass( A, TempA, Number, length );
        length *= 2;
        Merge_pass( TempA, A, Number, length );
        length *= 2;
    }
    TempA.clear();
}

ElementType Median3( vector<ElementType> &A, long int Left, long int Right ) {
    long int Center = (Left + Right) / 2 ;
    if ( A[Left] > A[Center] ) {
        Swap( &A[Left], &A[Center] );
    }
    if ( A[Left] > A[Right] ) {
        Swap( &A[Left], &A[Right] );
    }
    if ( A[Center] > A[Right]) {
        Swap( &A[Center], &A[Right] );
    }
    //现在，左、中、右三个已经有序
    Swap( &A[Center], &A[Right-1] );
    //现在只需考虑　Left+1 ~ Right-2
    return A[Right-1];
}
//快速排序算法实现
#define Cutoff 100 //定义快速排序（递归）阈值，数组元素小于Cutoff直接插入排序
void Quicksort( vector<ElementType> &A, long int Left, long int Right ) {
    ElementType pivot;
    long int i, j;
    //是否进行快速排序，阈值判断
    if ( (Right - Left) >= Cutoff ) {
        //选主元pivot，藏于A[Right-1]
        pivot = Median3 ( A, Left, Right );
        i = Left ;
        j = Right - 1 ;
        //子集划分(pivot左边全小于pivot；pivot右边全大于pivot)
        for ( ; ; ) {
            while ( A[++i] < pivot ) {} //找到A[i] > pivot, 跳出
            while ( A[--j] > pivot ) {} //找到A[j] < pivot, 跳出
            if ( i < j ) {
                //说明A[i]与A[j]之间还有其他元素，可交换
                Swap( &A[i], &A[j] );
            } else {
                break;
            }
        }
        Swap( &A[i], &A[Right-1] ); //将pivot 放到中间，即i下标处
        Quicksort( A, Left, i-1 );//递归处理左边
        Quicksort( A, i+1, Right );//递归处理右边
    } else {
        //低于阈值，直接调用插入排序
        //递归到最小一层用插入排序(每段的插入排序地址为：&A + Left (即：绝对地址A 加相对地址Left)
        //最小一层插入排序元素个数Number = Right-Left+1
        /*dosen't work
        ElementType *PartAddress = (ElementType*)( A + Left );
        Insertion_Sort ( PartAddress, Right-Left+1 );
        Insertion_Sort ( A + Left , Right-Left+1 );*/
        
    }
}
//快速排序（统一接口，加壳）
void Quick_Sort ( vector<ElementType> &A, long int Number ) {
    Quicksort ( A, 0, Number-1 );
}

