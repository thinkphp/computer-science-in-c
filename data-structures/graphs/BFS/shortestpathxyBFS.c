#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_QUEUE_SIZE 1000

// Structura pentru elementele din coadă
typedef struct {
    int vertex;
    int distance;
} QueueNode;

// Structura pentru coadă
typedef struct {
    QueueNode data[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

// Variabile globale
int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int n_vertices;

/**
 * Inițializează coada
 */
void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

/**
 * Verifică dacă coada este goală
 */
int is_queue_empty(Queue* q) {
    return q->front == q->rear;
}

/**
 * Adaugă un element în coadă
 */
void enqueue(Queue* q, int vertex, int distance) {
    if (q->rear < MAX_QUEUE_SIZE) {
        q->data[q->rear].vertex = vertex;
        q->data[q->rear].distance = distance;
        q->rear++;
    }
}

/**
 * Extrage un element din coadă
 */
QueueNode dequeue(Queue* q) {
    QueueNode node = {-1, -1}; // valori default pentru eroare
    if (!is_queue_empty(q)) {
        node = q->data[q->front];
        q->front++;
    }
    return node;
}

/**
 * Citește graful din fișier
 * Format: prima linie conține n, start_vertex, end_vertex
 *         următoarele n linii conțin matricea de adiacență
 */
int read_graph_from_file(const char* filename, int* start, int* end) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Eroare: Nu pot deschide fisierul %s\n", filename);
        return 0;
    }

    // Citește numărul de noduri și nodurile start/end
    if (fscanf(file, "%d %d %d", &n_vertices, start, end) != 3) {
        printf("Eroare: Format invalid in fisier\n");
        fclose(file);
        return 0;
    }

    printf("Numar de noduri: %d\n", n_vertices);
    printf("Caut calea de la nodul %d la nodul %d\n\n", *start, *end);

    // Citește matricea de adiacență
    printf("Matricea de adiacenta:\n");
    for (int i = 0; i < n_vertices; i++) {
        for (int j = 0; j < n_vertices; j++) {
            if (fscanf(file, "%d", &graph[i][j]) != 1) {
                printf("Eroare: Nu pot citi matricea de adiacenta\n");
                fclose(file);
                return 0;
            }
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    fclose(file);
    return 1;
}

/**
 * Scrie rezultatul în fișier
 */
void write_result_to_file(const char* filename, int start, int end, int distance) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Eroare: Nu pot crea fisierul %s\n", filename);
        return;
    }

    fprintf(file, "=== REZULTAT SHORTEST PATH ===\n\n");
    fprintf(file, "Graf cu %d noduri\n", n_vertices);
    fprintf(file, "Calea cautata: de la nodul %d la nodul %d\n\n", start, end);

    if (distance == -1) {
        fprintf(file, "REZULTAT: Nu exista cale intre nodul %d si nodul %d\n", start, end);
        printf("Nu exista cale intre nodul %d si nodul %d\n", start, end);
    } else {
        fprintf(file, "REZULTAT: Cea mai scurta cale are lungimea: %d\n", distance);
        printf("Cea mai scurta cale de la nodul %d la nodul %d: %d muchii\n", start, end, distance);
    }

    fclose(file);
}

/**
 * Implementează algoritmul BFS pentru găsirea celei mai scurte căi
 * Returnează lungimea căii sau -1 dacă nu există cale
 */
int shortest_path_bfs(int start, int end) {
    // Cazul trivial
    if (start == end) {
        return 0;
    }

    // Verifică dacă nodurile sunt valide
    if (start < 0 || start >= n_vertices || end < 0 || end >= n_vertices) {
        printf("Eroare: Noduri invalide (start=%d, end=%d, max=%d)\n", start, end, n_vertices-1);
        return -1;
    }

    // Inițializează structurile de date
    Queue q;
    init_queue(&q);

    // Marchează toate nodurile ca nevizitate
    for (int i = 0; i < n_vertices; i++) {
        visited[i] = 0;
    }

    // Începe BFS-ul
    enqueue(&q, start, 0);
    visited[start] = 1;

    printf("Incep BFS de la nodul %d...\n", start);

    while (!is_queue_empty(&q)) {
        QueueNode current = dequeue(&q);

        if (current.vertex == -1) {
            break; // Eroare la dequeue
        }

        printf("Vizitez nodul %d (distanta %d)\n", current.vertex, current.distance);

        // Explorează toți vecinii nodului curent
        for (int neighbor = 0; neighbor < n_vertices; neighbor++) {
            // Verifică dacă există muchie și vecinul nu a fost vizitat
            if (graph[current.vertex][neighbor] == 1 && !visited[neighbor]) {
                // Dacă am găsit nodul destinație
                if (neighbor == end) {
                    printf("Gasit nodul destinatie %d!\n", end);
                    return current.distance + 1;
                }

                // Marchează vecinul ca vizitat și îl adaugă în coadă
                visited[neighbor] = 1;
                enqueue(&q, neighbor, current.distance + 1);
                printf("  -> Adaug vecinul %d in coada (distanta %d)\n", neighbor, current.distance + 1);
            }
        }
    }

    printf("BFS terminat - nu s-a gasit cale\n");
    return -1; // Nu există cale
}

/**
 * Afișează meniul și gestionează input-ul utilizatorului
 */
void display_menu() {
    printf("\n=== SHORTEST PATH cu BFS ===\n\n");
    printf("Acest program calculeaza cea mai scurta cale intr-un graf neponderat\n");
    printf("folosind algoritmul Breadth-First Search (BFS).\n\n");
    printf("Format fisier de intrare 'graph.txt':\n");
    printf("Prima linie: n start_vertex end_vertex\n");
    printf("Urmatoarele n linii: matricea de adiacenta n x n\n\n");
    printf("Exemplu:\n");
    printf("5 0 4\n");
    printf("0 1 1 0 0\n");
    printf("1 0 0 1 1\n");
    printf("1 0 0 0 1\n");
    printf("0 1 0 0 1\n");
    printf("0 1 1 1 0\n\n");
}

/**
 * Funcția principală
 */
int main() {
    display_menu();

    int start_vertex, end_vertex;

    // Citește graful din fișier
    if (!read_graph_from_file("graph.txt", &start_vertex, &end_vertex)) {
        return 1;
    }

    // Calculează cea mai scurtă cale
    printf("Calculez cea mai scurta cale...\n\n");
    int distance = shortest_path_bfs(start_vertex, end_vertex);

    // Scrie rezultatul în fișier
    write_result_to_file("shortest_path_result.txt", start_vertex, end_vertex, distance);

    printf("\nRezultatul a fost salvat in 'shortest_path_result.txt'\n");

    return 0;
}

/*
=== EXEMPLU DE FISIER graph.txt ===

5 0 4
0 1 1 0 0
1 0 0 1 1
1 0 0 0 1
0 1 0 0 1
0 1 1 1 0

Explicație:
- 5 noduri (0, 1, 2, 3, 4)
- Căutăm calea de la nodul 0 la nodul 4
- Matricea de adiacență 5x5

Graful arată astfel:
    0 --- 1 --- 3
    |     |     |
    2 --------- 4

Calea cea mai scurtă: 0 -> 1 -> 4 (lungime 2)

=== ALT EXEMPLU ===

4 0 3
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0

Explicație:
- 4 noduri formând un ciclu
- Căutăm calea de la 0 la 3
- Calea: 0 -> 3 (lungime 1)

=== EXEMPLU FĂRĂ CALE ===

4 0 3
0 1 0 0
1 0 0 0
0 0 0 1
0 0 1 0

Explicație:
- Nodurile 0,1 sunt conectate
- Nodurile 2,3 sunt conectate
- Nu există cale între cele două componente
- Rezultat: -1 (nu există cale)
*/
