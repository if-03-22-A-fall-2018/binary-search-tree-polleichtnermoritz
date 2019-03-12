#include <stdio.h>
#include "bst.h"
#include <stdlib.h>
#include "general.h"
#define MAXL 50

struct Node{
  int data;
   Bst left_subtree;
   Bst right_subtree;
};

Bst new_bst(){
   Bst _head = 0;
   return _head;
}
void delete_bst(Bst bst){
  if(bst == 0)return;
  delete_bst(bst->left_subtree);
  delete_bst(bst->right_subtree);
  sfree(bst);
}

int get_depth(Bst bst){
  if(bst == 0)return 0;
  int depth = get_depth(bst->left_subtree)+1;
  int r = get_depth(bst->right_subtree)+1;
  return  r>depth ? r:depth;
}

void add(Bst* bst, int value){
  Bst &aka = *bst;
  if(aka == 0){
    aka = (Bst)malloc(sizeof(struct Node));
    aka->data = value;
    aka->left_subtree =0;
    aka->right_subtree =0;
  }
  else if(value <= aka->data){
      add(&aka->left_subtree, value);
  }
  else{
      add(&aka->right_subtree,value);
  }
}

int root_value(Bst bst){
  return bst==0?0:bst->data;
}

Bst left_subtree(Bst root){
  return root == 0?0:root->left_subtree;
}

Bst right_subtree(Bst root){
  return root == 0?0:root->right_subtree;
}

int traverse_pre_order(Bst bst, int *elements, int start){
    
}

int traverse_in_order(Bst bst, int *elements, int start){
    return 0;
}

int traverse_post_order(Bst bst, int *elements, int start){
    return 0;
}

bool are_equal(Bst bst1, Bst bst2){
  return false;
}

void most_left_longest_branch(Bst bst, Bst* branch){
    if(bst == 0)return;
    add(branch, bst->data);
    get_depth(bst->left_subtree) >= get_depth(bst->right_subtree) ? most_left_longest_branch(bst->left_subtree, branch):most_left_longest_branch(bst->right_subtree, branch);
}

int get_number_of_subtrees(Bst bst){
  return 0;
}
