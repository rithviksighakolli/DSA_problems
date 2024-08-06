#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
bool find(char grid[100][100],char word[100],int startx,int starty,int xincrement,int yincrement,int n,int *length){
    int len=strlen(word);
    *length=0;
    for(int i=0;i<len;i++){
        if(startx<0||startx>=n||starty<0||starty>=n||grid[startx][starty]!=word[i]){
            return false;
        }
        startx+=xincrement;
        starty+=yincrement;
        (*length)++;
    }
    return true;
}
void search(char grid[100][100],char wordsearch[100][100],int n,int no){
    for(int i=0;i<no;i++){
        char *word=wordsearch[i];
        int len=strlen(word);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                int length=0;
                // Check horizontally
                if(col+len<=n&&find(grid,word,row,col,0,1,n,&length)){
                    printf("The word '%s' has the parameters (n=%d,m=%d,l=%d) and found horizontally\n",word,row,col,length);
                }
                // Check vertically
                if(row+len<=n&&find(grid,word,row,col,1,0,n,&length)){
                    printf("The word '%s' has the parameters (n=%d,m=%d,l=%d) and found vertically\n",word,row,col,length);
                }
                // Check reverse horizontally
                if(col-len+1>=0&&find(grid,word,row,col,0,-1,n,&length)){
                    printf("The word '%s' has the parameters (n=%d,m=%d,l=%d) and found reverse horizontally\n",word,row,col,length);
                }
                // Check reverse vertically
                if(row-len+1>=0&&find(grid,word,row,col,-1,0,n,&length)){
                    printf("The word '%s' has the parameters (n=%d,m=%d,l=%d) and found reverse vertically\n",word,row,col,length);
                }
            }
        }
    }
}
int main() {
    int n;
    clock_t start,end;
    printf("Enter the size of the grid: ");
    scanf("%d",&n);
    char grid[100][100];
    printf("Enter the characters of the grid: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf(" %c",&grid[i][j]);
        }
    }
    int no;
    printf("Enter the number of words in the word bank: ");
    scanf("%d",&no);
    char word[100][100];
    printf("Enter the words of the word bank: \n");
    for(int i=0;i<no;i++){
        scanf("%s",word[i]);
    }
    start=clock();
    search(grid,word,n,no);
    end=clock();
    double time=(double)((end-start)*1000)/CLOCKS_PER_SEC;
    printf("The time taken is %.3lf ms",time);
    return 0;
}