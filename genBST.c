#include <stdio.h>/* for prints*/
#include<stdlib.h>/* size_t malloc*/
#include "genBST.h"

static void PrintIntInOrder(BSNode * _nd);

static void DeletePostOrder(BSNode * _nd ,  void (*_destroyer)(void*));
static void AssignData( BSNode * _nd , void* _item);
static BSNode* searchPlaceToInsert(BSNode * _temp , BSNode * _temp2, void*  _data, LessComparator _less);

static void leaf(BSNode* _node);
static void OneChild(BSNode* _nd);
static void TwoChild(BSNode* _nd);

struct BSNode
{
	void* m_data;
	BSNode* m_left;
	BSNode* m_right;
	BSNode* m_father;
};

struct BSTree
{
	BSNode m_sentinal;
	LessComparator m_compare;
};

BSTree* BSTreeCreate(LessComparator _less)
{
	BSTree * tree;
	if(_less == NULL)
	{
		return NULL;
	}
	tree = (BSTree*)malloc(sizeof(BSTree));
	if(tree == NULL)
	 {
	     return NULL;
	 }
	 tree -> m_sentinal.m_father =& tree ->m_sentinal;
	 tree -> m_sentinal.m_right = NULL;
	 tree -> m_sentinal.m_left = NULL;
	 tree -> m_sentinal.m_data = NULL;
	 tree -> m_compare = _less;	 
	 return tree;
}


void  BSTreeDestroy(BSTree** _tree, void (*_destroyer)(void*))
{
	if(_tree == NULL || *_tree == NULL )
	{
		return ;
	}
	if(_destroyer != NULL && (*_tree)->m_sentinal.m_left != NULL)
	{
			DeletePostOrder((*_tree) -> m_sentinal.m_left ,  _destroyer);
	}
	free(*_tree);
	*_tree = NULL; /*in the tests - check null*/
}

static void DeletePostOrder(BSNode * _nd ,  void (*_destroyer)(void*))
{
	if(_nd  == NULL)
	{
		return ;
	}	
	DeletePostOrder( _nd -> m_left , _destroyer);
	DeletePostOrder( _nd -> m_right , _destroyer);
	if(_destroyer != NULL)
	{
		_destroyer(_nd -> m_data);
	}	
		free(_nd);
}

BSTreeItr BSTreeInsert(BSTree* _tree, void* _item)
{
	BSNode* nd;
	BSNode* temp ;
	BSNode* leaf;
	BSNode* temp2 = NULL;
/*	if( _item == NULL)
	{
		return th end  - do macro of end
	} */
	if(_tree == NULL)
	{
		return NULL;
	}
	nd = (BSNode*)malloc(sizeof(BSNode));
	if (nd == NULL)
	{
		return NULL;
		/*return th end  - do macro of end */
	}
	AssignData( nd , _item);
	if (_tree -> m_sentinal.m_left == NULL)
	{
		_tree -> m_sentinal.m_left  = nd;
		return (void*)nd;
	}
	temp = _tree -> m_sentinal.m_left;
	leaf = searchPlaceToInsert(temp ,temp2, _item, _tree->m_compare);
	if (!leaf )
	{
		return _item;
	}
	if (_tree->m_compare(_item , leaf -> m_data) == -1)
	{
       	leaf -> m_right = nd;
    }else
    {
	    leaf ->m_left= nd;
	}
	nd -> m_father = leaf;  
	return (void*)nd;
}
/*
int Compare(void* _left, void* _right)
{
	if(_left < _right)
	{
		return -1;
	}
	if(_left > _right)
	{
		return 1;
	}
	if(_left == _right)
	{
		return 0;
	}
}
*/

static BSNode* searchPlaceToInsert(BSNode * _temp , BSNode * _temp2, void*  _data, LessComparator _less)
{
	
	while (_temp != NULL)
	{
		_temp2 = _temp;
		if (_less(_data , _temp -> m_data) == 1) 
		{
			_temp = _temp -> m_left;
		}else if (_less(_data  , _temp -> m_data) == -1)
		{
			_temp = _temp -> m_right;
		}else
		{
			return NULL;
		}
	}
	return _temp2;
}

static void AssignData( BSNode * _nd , void*  _item)
{
	_nd -> m_data = _item;
	_nd -> m_left = NULL;
	_nd -> m_right = NULL;
}

static void PrintIntInOrder(BSNode * _nd)
{
	if(_nd  == NULL)
	{
		return ;
	}	
	PrintIntInOrder( _nd -> m_left);
	printf(" %d" , *(int*)_nd -> m_data);
	PrintIntInOrder( _nd -> m_right);
}

void TreePrintInt(BSTree* _tree)
{
	 BSNode * nd;
	if (_tree != NULL)
	{
		nd = _tree -> m_sentinal.m_left ;
		PrintIntInOrder(nd);
  		printf("\n");
	}
}

BSTreeItr BSTreeItrBegin(const BSTree* _tree)
{
	BSNode* nd;
/*	BSNode* temp; */
	if(_tree == NULL)
	{
		return ;
	}
/*	if (_tree -> m_sentinal.m_left == NULL)
	{
		return (void*)&_tree -> m_sentinal;
	} *//* can check it inside the loop */
	nd = &_tree -> m_sentinal;
	while (nd != NULL)
	{
	/*	temp = nd; */
		nd = nd -> m_left;
	}
	return (BSTreeItr)nd;
}

BSTreeItr BSTreeItrEnd(const BSTree* _tree)
{
	if(_tree == NULL)
	{
		return ;
	}
	return (BSTreeItr)&(_tree -> m_sentinal);
}

int BSTreeItrEquals(BSTreeItr _a, BSTreeItr _b)
{
	if(_a == NULL || _b == NULL)
	{
		return ;
	}
	return _a == _b;
}

void* BSTreeItrGet(BSTreeItr _it)
{
	if(_it == NULL || _it == _it -> m_father)
	{
		return ;
	}
	return ((BSNode*)_it) -> m_data;
}


BSTreeItr BSTreeItrNext(BSTreeItr _it)
{
	BSNode* temp;
	BSNode* nd;
	BSNode* father;
	if(_it == NULL || (BSNode*)_it -> m_father == (BSNode*)_it)
	{
		return NULL;
	}
	nd = (BSNode*)_it;
	if(((BSNode*)_it) -> m_right == NULL)
	{
		father = ((BSNode*)_it) ->m_father;
		while (father -> m_right == nd)
		{
			nd = father ;
			father = father->m_father;
		}
		return (BSTreeItr)father ;
	 }
	_it = ((BSNode*)_it) -> m_right;
	while (((BSNode*)_it) -> m_left != NULL)
	{
		_it = ((BSNode*)_it) -> m_left;
	}
	return (BSTreeItr)_it ;
}


BSTreeItr BSTreeItrPrev(BSTreeItr _it)
{
	BSNode* temp;
	BSNode* nd;
	BSNode* father;
	if(_it == NULL)
	{
		return _it;
	}
	nd = (BSNode*)_it;
	if(((BSNode*)_it) -> m_left == NULL)
	{
		father = ((BSNode*)_it) ->m_father;
		while (father -> m_left == nd)
		{
			nd = father ;
			father = father->m_father;
		}
		return (BSTreeItr)father ;
	 }
	_it = ((BSNode*)_it) -> m_left;
	temp = _it;
	while (((BSNode*)_it) -> m_right != NULL)
	{
		_it = ((BSNode*)_it) -> m_right;
		temp = _it;
	}
	return (BSTreeItr)_it ;
}

void* BSTreeItrRemove(BSTreeItr _it)
{
	BSNode* nd;
	BSNode* ret;
	BSNode* father;
	if(_it == NULL)
	{
		return NULL;
	}
	nd = (BSNode*)_it;
	ret = nd -> m_data;
	father = nd -> m_father;
	if ( nd -> m_right == NULL && nd -> m_left == NULL)
	{
		leaf(nd);
		/*should return the removed value*/
	}
	if ( nd -> m_right == NULL && nd -> m_left != NULL ||
	nd -> m_right != NULL && nd -> m_left == NULL)
	{
		OneChild(nd);
				/*should return the removed value*/
	}
	if ( nd -> m_right != NULL && nd -> m_left != NULL)
	{
		TwoChild(nd);
				/*should return the removed value*/
	}
	return (void*)ret;
}

static void TwoChild(BSNode* _nd)
{
    BSNode * next;
    BSNode * temp;
    next = BSTreeItrNext(_nd);
    _nd -> m_data = next -> m_data;
	if ( next -> m_right == NULL && next -> m_left == NULL)
	{
		leaf(next);
	}
	if ( next -> m_right == NULL && next -> m_left != NULL ||
	next -> m_right != NULL && next -> m_left == NULL)
	{
		OneChild(next);
	}
}


static void OneChild(BSNode* _nd)
{
    BSNode * father;
    father = _nd->m_father;
	if (father -> m_right == _nd)
	{
		if ( _nd -> m_right != NULL && _nd -> m_left == NULL )
		{
			father -> m_right = _nd -> m_right;		
		}else
		{
			father -> m_right = _nd -> m_left;					
		}
		free(_nd);
	}
	if (father -> m_left == _nd)
	{
		if ( _nd -> m_right == NULL && _nd -> m_left != NULL )
		{
			father -> m_left = _nd -> m_left;		
		}else
		{
			father -> m_left = _nd -> m_left;					
		}
		free(_nd);
	}
}


static void leaf(BSNode* _nd)
{
    BSNode * father;
    father = _nd->m_father;
	if (father -> m_right == _nd)
	{
		father -> m_right = NULL;
	}
	if (father -> m_left == _nd)
	{
		father -> m_left = NULL;
	}
	free(_nd);
}


/*

static void leaf(BSNode* _node)
{
    BSNode * temp;
    temp = _node->m_father;
    if(temp->m_right == _node)
    {
        temp->m_right = NULL;
    }
    temp->m_left = NULL;
    free(_node);
}


BSTreeItr BSTreeItrNext(BSTreeItr _it)
{
	BSNode* temp;
	BSNode* nd;
	BSNode* father;
	if(_it == NULL)
	{
		return _it;
	}
	nd = (BSNode*)_it;
	if(((BSNode*)_it) -> m_right == NULL)
	{
		father = ((BSNode*)_it) ->m_father;
		while (father -> m_right == (BSNode*)_it)
		{
			_it = father ;
			father = father->m_father;
			if(father -> m_right  == NULL)
			{
				return;
			} 
		}
		return (void*)father ;
	 }
	_it = ((BSNode*)_it) -> m_right;
	temp = _it;
	while (((BSNode*)_it) -> m_left != NULL)
	{
		_it = ((BSNode*)_it) -> m_left;
		temp = _it;
	}
	return (void*)temp ;
}

*/

