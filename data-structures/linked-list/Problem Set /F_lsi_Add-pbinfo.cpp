void LsiAdd(struct Nod *& head, int val, int x, int y) {

      struct Nod *q;

      if(head->info == val) { //if the node is first then execute

         q = new Nod;
         q->info = x;
         q->leg = head;
         head = q;

      struct Nod *c = head, *new_node;

      while( c->info != val ) c = c->leg;

         new_node = new Nod;
          
         new_node->info = y;
          
         new_node->leg = c->leg;
          
         c->leg = new_node;

      } else {

        struct Nod *c = head, *new_node, *aux, *new_node2;

        while(c->leg!=NULL && c->leg->info != val ) c = c->leg;
          
          if(c!=nullptr && c->leg!=NULL) {  

             aux = c->leg;

             new_node = new Nod;
             new_node->info = x;
             new_node->leg = c->leg;
             c->leg = new_node;


             new_node2 = new Nod;
             new_node2->info = y;
             new_node2->leg = aux->leg;
             aux->leg = new_node2;
              
          }
      }   

}
