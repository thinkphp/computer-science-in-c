void FAdaugaInainte(Nod *&head) {
    
    struct Nod *c;
    c = head;

    if (c->info &1) {
        
        struct Nod *new_node = new Nod;
        
        new_node->info = head->info * 2;
        
        new_node->leg = head;
        
        head = new_node;        
    }

    while (c->leg != NULL) {
        
        if (c->leg->info & 1) {
            
            struct Nod *q;
            
            q = new Nod;
            
            q->info = c->leg->info * 2;
            
            q->leg = c->leg;                        
            
            c->leg = q;
            
            c = q->leg;
            
        } else
            
            c = c->leg;
    }
}
