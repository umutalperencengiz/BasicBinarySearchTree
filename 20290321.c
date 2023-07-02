#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct student{
    int studentID ;
    int grade;
    struct student *left, *right;
};

void insert_tree(struct student **start,int studentID,int grade)
{
    struct student *ptr = *start;
    
    
    
    
    if(ptr == NULL)
    {
    ptr = (struct student*)malloc(sizeof(struct student));
    ptr->studentID = studentID;
    ptr->grade = grade;
    ptr->left = NULL;
    ptr->right = NULL;
    *start = ptr;
    }
    else 
    {
        if(grade < ptr->grade) 
        {
            
          
        insert_tree(&ptr->left,studentID,grade);
        //printf("%d %d (%d L)\n",studentID,grade,ptr->grade);
        }
        
        else 
        {
        insert_tree(&ptr->right,studentID,grade);
        //printf("%d %d (%d R)\n",studentID,grade,ptr->grade);
        }
    }
}
void print_parentL(struct student *start,int level) 
{
  struct student *ptr ;
  ptr = start ;
  if(ptr ==NULL) ;
  else if(level==0);
  else
  {

        if(ptr->left &&level ==1) 
        {
           printf("(%d L) ",ptr->grade);
        }
 }
}
void print_parentR(struct student *start,int level) 
{
  struct student *ptr ;
  ptr = start ;
  if(ptr ==NULL) ;
  else if(level==0 );
  else
  {

        if(ptr->right && level == 1) 
        {
           printf("(%d R) ",ptr->grade);
        }
 }
}
void sortGrades(struct student *start)
{
    struct student *ptr ;
    ptr = start ;
    if(ptr == NULL);
    else
    {
    sortGrades(ptr->left);
    
        if(ptr->left == NULL || ptr->grade > ptr->left->grade ) // or statement is essential when I dont use the output happened quite different 
        {
            printf("%d %d\n",ptr->studentID,ptr->grade);
            
            //printf("%d %d\n",ptr->left->studentID,ptr->left->grade);
           }
        
        else if(ptr->right ==NULL || ptr->grade < ptr->right->grade) 
        {
            
            //printf("%d %d\n",ptr->right->studentID,ptr->right->grade);
            
            printf("%d %d\n",ptr->studentID,ptr->grade);
            
        }
        sortGrades(ptr->right);
    }
}
int total_levels(struct student* start) 
{
    if (start ==NULL)  return 0;
    else 
    {

        int left_levels = total_levels(start->left);
        int right_levels = total_levels(start->right);
        if (left_levels >= right_levels)
            return left_levels+ 1;
        else
            return right_levels+ 1;
    }
}
void print_level(struct student* start, int level) 
{
    struct student *ptr = start;
    
    if (ptr == NULL) return;  // if you dont use return it would go else statement then some results wont be shown in terminal
    if (level == 0) 
    {
        printf("%d %d ", ptr->studentID,ptr->grade);
        
        
    }
    else 
    {
        
        print_level(ptr->left, level-1);
        print_parentL(ptr,level);
        print_level(ptr->right, level-1);
        print_parentR(ptr,level);
    }

}

void print_tree_level_order(struct student* start) {
    if (start ==NULL) return;
    int levels = total_levels(start);
    for (int i=0; i<levels; i++) {
        print_level(start, i);
        printf("\n");
    }
   
}
int main()
{
    struct student* start = NULL;
    int studentID, grade;
    scanf("%d",&studentID);
    while(studentID != -1)
    {
        scanf("%d",&grade);
        insert_tree(&start,studentID,grade); // for decode in order binary tree
        scanf("%d",&studentID);
    }
    sortGrades(start);
    puts("");
    print_tree_level_order(start);
    
}
