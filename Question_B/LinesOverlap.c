//Program to check whether lines overlap

#include<stdio.h>

//Macros to find minimum and maximum of given values
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

//Structure definition for a point 
struct point
{
    int x;
    int y;
};

//Declaration of function to be used
int overlap(struct point a1, struct point b1, struct point a2, struct point b2);
int collinear(struct point a, struct point b, struct point c);
int onLine(struct point a, struct point b, struct point c);

int main()
{
    int ans;	//Variable to hold answer whether lines overlap or not
    struct point a1,b1,a2,b2; 	//Structure variable declaration 
  
    //Get coordinates for both the lines
    //Line 1
    printf("\nEnter coordinates for line 1 (point 1)\n");
    scanf("%d,%d",a1.x,a1.y);
    printf("\nEnter coordinates for line 1 (point 2)\n");
    scanf("%d,%d",b1.x,b1.y);
    
    //Line 2
    printf("\nEnter coordinates for line 2 (point 1)\n");
    scanf("%d,%d",a2.x,a2.y);
    printf("\nEnter coordinates for line 2 (point 2)\n");
    scanf("%d,%d",b2.x,b2.y);
    
    //overlap function call, passing all coordinates 
    ans = overlap(a1,b1,a2,b2);
    //Checks lines overlap
    if (ans==1)
        printf("\nYes, lines overlap\n");
    else
        printf("\nNo, lines don't overlap\n");
    return 0;
}

//Function to check if lines overlap or not
int overlap(struct point a1, struct point b1, struct point a2, struct point b2)
{
    //Call function collinear to check if points are collinear
    int co1 = collinear(a1, b1, a2); 
    int co2 = collinear(a1, b1, b2); 
    int co3 = collinear(a2, b2, a1); 
    int co4 = collinear(a2, b2, b1);

    // Passing any three point and check they are collinear and any one lies on line.
    // a1, b1 and a2 are collinear and a2 lies on line 1
    if (co1 == 1 && onLine(a1, a2, b1))
        return 1; 
  
    // a1, b1 and b2 are collinear and b2 lies on line1 
    if (co2 == 1 && onLine(a1, b2, b1))
        return 1; 
  
    // a2, b2 and a1 are collinear and a1 lies on line 2 
    if (co3 == 1 && onLine(a2, a1, b2))
        return 1; 
  
     // a2, b2 and b1 are collinear and b1 lies on line 2 
    if (co4 == 1 && onLine(a2, b1, b2))
        return 1; 
    
   //If points are not collinear and doesn’t line on any line   
    return 0;
}

//Function to check whether points are collinear
int collinear(struct point a, struct point b, struct point c)
{
    //Calculate points are in collinear using slope equation
    int check=(b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y); 
  
    //Check whether points are collinear  
    if(check==0)
        return 1; 	//Yes, points are collinear
        
    return 0; 	//No, points are not collinear
}

//Function to check if point lies on the line
int onLine(struct point a, struct point b, struct point c)
{
    //If point satisfies equation of line then it lies on the line 
    if (b.x <= MAX(a.x, c.x) && b.x >= MIN(a.x, c.x) && 
        b.y <= MAX(a.y, c.y) && b.y >= MIN(a.y, c.y)) 
       return 1; 	//Point lies on the line
  
    return 0; 	//Point don’t lie on the line 
}
