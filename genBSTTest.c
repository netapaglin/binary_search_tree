#include <stdio.h>/* for prints*/
#include "genBST.h"

int Compare(void* _left, void* _right);
int CompareInt(void* _left, void* _right);

void testCreateNoremal();

void testDestroy();
void testDoubleDestroy();

void testInsert();

void testBegin();

void testBeginNextNormal();

void testBeginPrevNormal();

void testRemoveLeaf();
void testRemoveOneChild();
void testRemoveTwoChild();

int main(void)
{

	testCreateNoremal();
	
	testDestroy();
	testDoubleDestroy();
	
	testInsert();
	
	testBegin();
	
	testBeginNextNormal();
	
	testBeginPrevNormal();
	
	testRemoveLeaf();
/*		testRemoveOneChild(); */
	testRemoveTwoChild(); 
	return 1;
}

void testRemoveTwoChild()
{
	BSTree * t;
	BSTreeItr x , y;
	int i;

	int arr[] ={9,3,5,6,8,11,17,20,4,10,1,15};
	

	t =  BSTreeCreate(CompareInt);
	for( i =0 ; i < 12; ++i)
	{
		BSTreeInsert(t, &arr[i]);
	}
	TreePrintInt(t);
	x = BSTreeItrBegin(t);
	printf(" Get 1 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 2 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 3 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 4 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 5 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 6 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 7 %d \n" , *(int*)BSTreeItrGet(x));
	/*********/	BSTreeItrRemove(x);  /****************/	
	x =BSTreeItrNext(x);
	printf(" Get 8 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 9 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 10 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 11 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 12 %d \n" , *(int*)BSTreeItrGet(x));
	TreePrintInt(t);
	if ( 3 == 2)
	{
	 	printf("test remove two child -PASS\n");
	 }else
	 {
	 	printf("test remove two child  return value-FAIL\n");
	 }
	 BSTreeDestroy(&t , NULL);
}



void testRemoveOneChild()
{
	BSTree * t;
	BSTreeItr x , y;
	int i;
	int arr[] ={9,3,5,6,8,11,17,20,4,10,1,15};
	t =  BSTreeCreate(CompareInt);
	for( i =0 ; i < 12; ++i)
	{
		BSTreeInsert(t, &arr[i]);
	}
	TreePrintInt(t);
	x = BSTreeItrBegin(t);
	printf(" Get 1 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 2 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 3 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 4 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 5 %d \n" , *(int*)BSTreeItrGet(x));
		BSTreeItrRemove(x); 
/*	x =BSTreeItrNext(x);
	printf(" Get 6 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 7 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 8 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 9 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 10 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 11 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 12 %d \n" , *(int*)BSTreeItrGet(x));
*/
	TreePrintInt(t);
	if ( 3 == 2)
	{
	 	printf("test remove one child -PASS\n");
	 }else
	 {
	 	printf("test remove one child  return value-FAIL\n");
	 }
	 BSTreeDestroy(&t , NULL);
}


void testRemoveLeaf()
{
	BSTree * t;
	BSTreeItr x , y;
	int i;
	int arr[] ={9,3,5,6,8,11,17,20,4,10,1,15};
	t =  BSTreeCreate(CompareInt);
	for( i =0 ; i < 12; ++i)
	{
		BSTreeInsert(t, &arr[i]);
	}
	TreePrintInt(t);
	x = BSTreeItrBegin(t);
	printf(" Get 1 %d \n" , *(int*)BSTreeItrGet(x));

	x =BSTreeItrNext(x);
	printf(" Get 2 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 3 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 4 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 5 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 6 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 7 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 8 %d \n" , *(int*)BSTreeItrGet(x));
	y =	BSTreeItrRemove(x);
	
	TreePrintInt(t);
	
	/*	

	printf(" Get 6 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 7 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 8 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 9 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 10 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 11 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 12 %d \n" , *(int*)BSTreeItrGet(x));
*/
	
	if ( 3 == 2)
	{
	 	printf("test remove leaf -PASS\n");
	 }else
	 {
	 	printf("test remove leaf return value-FAIL\n");
	 }
	 BSTreeDestroy(&t , NULL);
}


void testBeginPrevNormal()
{
	BSTree * t;
	BSTreeItr x , y;
	int i;
	int arr[] ={9,3,5,6,8,11,17,20,4,10,1,15};
	t =  BSTreeCreate(CompareInt);
	for( i =0 ; i < 12; ++i)
	{
		BSTreeInsert(t, &arr[i]);
	}
		TreePrintInt(t);
	x = BSTreeItrEnd(t);
	printf(" Get 1 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 2 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 3 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 4 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 5 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 6 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 7 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 8 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 9 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 10 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 11 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 12 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrPrev(x);
	printf(" Get 13 %d \n" , *(int*)BSTreeItrGet(x));
/*		x =BSTreeItrPrev(x);
	printf(" Get 14 %d \n" , *(int*)BSTreeItrGet(x));
		
		x =BSTreeItrNext(x); */
	
	if ( *(int*)BSTreeItrGet(x) == 2)
	{
	 	printf("test prev -PASS\n");
	 }else
	 {
	 	printf("test prev-FAIL\n");
	 }
	 BSTreeDestroy(&t , NULL);
}


void testBeginNextNormal()
{
	BSTree * t;
	BSTreeItr x , y;
	int i;
	int arr[] ={9,3,5,6,8,11,17,20,4,10,1,15};
	t =  BSTreeCreate(CompareInt);
	for( i =0 ; i < 12; ++i)
	{
		BSTreeInsert(t, &arr[i]);
	}
		TreePrintInt(t);
	x = BSTreeItrBegin(t);
	printf(" Get 1 %d \n" , *(int*)BSTreeItrGet(x));
	x =BSTreeItrNext(x);
	printf(" Get 2 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 3 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 4 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 5 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 6 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 7 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 8 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 9 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 10 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 11 %d \n" , *(int*)BSTreeItrGet(x));
		x =BSTreeItrNext(x);
	printf(" Get 12 %d \n" , *(int*)BSTreeItrGet(x));
		
		/*	x =BSTreeItrNext(x); */
	
	if ( *(int*)BSTreeItrGet(x) == 2)
	{
	 	printf("test next -PASS\n");
	 }else
	 {
	 	printf("test next-FAIL\n");
	 }
	 BSTreeDestroy(&t , NULL);
}




void testBegin()
{
	BSTree * t;
	BSTreeItr x;
	int a =7 , b = 3 , c = 9, d = 20, e = 1, f =8;
	t =  BSTreeCreate(CompareInt);
	BSTreeInsert(t, &a);
	BSTreeInsert(t, &b);
	BSTreeInsert(t, &d);
	BSTreeInsert(t, &c);
	BSTreeInsert(t, &e);
	BSTreeInsert(t, &f);
	x = BSTreeItrBegin(t);
	
	
	if ( *(int*)BSTreeItrGet(x) == 1)
	{
	 	printf("test begin -PASS\n");
	 }else
	 {
	 	printf("test begin-FAIL\n");
	 }
	 BSTreeDestroy(&t , NULL);
}



int CompareInt(void* _left, void* _right)
{
	if(*(int*)_left < *(int*)_right)
	{
		return 1;
	}
	if(*(int*)_left > *(int*)_right)
	{
		return -1;
	}
	if(*(int*)_left == *(int*)_right)
	{
		return 0;
	}
}

void testInsert()
{
	BSTree * t;
	int a =7 , b = 3 , c = 9, d = 20, e = 1, f =8;
	t =  BSTreeCreate(CompareInt);
	BSTreeInsert(t, &a);
	BSTreeInsert(t, &b);
	BSTreeInsert(t, &d);
	BSTreeInsert(t, &c);
	BSTreeInsert(t, &e);
	BSTreeInsert(t, &f);
	TreePrintInt(t);
	BSTreeDestroy(&t , NULL);
}


void testDoubleDestroy()
{
	BSTree * t;
	t =  BSTreeCreate(Compare);
	BSTreeDestroy(&t , NULL);
	BSTreeDestroy(&t , NULL);
	printf("test double destroy -PASS\n");
}


void testDestroy()
{
	BSTree * t;
	t =  BSTreeCreate(Compare);
	BSTreeDestroy(&t , NULL);
	printf("test destroy -PASS\n");
}

int Compare(void* _left, void* _right)
{
	if(_left < _right)
	{
		return 1;
	}
	if(_left > _right)
	{
		return -1;
	}
	if(_left == _right)
	{
		return 0;
	}
}

void testCreateNoremal()
{
	BSTree * t;
	t =  BSTreeCreate(Compare);
	if (t  != NULL)
	 {
	 	printf("test create  normal -PASS\n");
	 }else
	 {
	 	printf("test create  normal -FAIL\n");
	 }
}

