//
//  main.c
//  2020_12_25_01
//
//  Created by dulei on 2020/12/25.
//

#include <stdio.h>
#include "queue.h"
#include "huffman.h"

int main(int argc, const char * argv[]) {
    
    hmTree *codeTree = build_tree("abcdadf");
    hlTable *table = build_table(codeTree);
    return 0;
}
