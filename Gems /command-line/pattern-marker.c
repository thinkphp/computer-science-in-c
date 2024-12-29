#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096
#define MAX_FILE_SIZE 1000000

char* markPattern(const char* content, const char* pattern) {

    char* result = malloc(MAX_FILE_SIZE);
    
    char* temp = result;
    const char* pos = content;

    if (!result) {
        return NULL;
    }

    *temp = '\0';

    while ((pos = strstr(pos, pattern)) != NULL) {
        // Copy everything up to the pattern
        strncat(result, content, pos - content);

        // Add opening mark tag
        strcat(result, "<mark>");

        // Add the pattern itself
        strcat(result, pattern);

        // Add closing mark tag
        strcat(result, "</mark>");

        // Update content pointer to skip past the pattern
        content = pos + strlen(pattern);
        pos = content;
    }

    // Add remaining content
    strcat(result, content);

    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <pattern>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Error: Cannot open file %s\n", argv[1]);
        return 1;
    }

    // Read file content
    char* content = malloc(MAX_FILE_SIZE);
    if (!content) {
        printf("Error: Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    size_t total_read = 0;
    size_t bytes_read;
    char buffer[BUFFER_SIZE];

    content[0] = '\0';
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE - 1, file)) > 0) {
        buffer[bytes_read] = '\0';
        strcat(content, buffer);
        total_read += bytes_read;

        if (total_read >= MAX_FILE_SIZE - BUFFER_SIZE) {
            printf("Error: File too large\n");
            free(content);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // Process the content
    char* marked_content = markPattern(content, argv[2]);
    if (!marked_content) {
        printf("Error: Memory allocation failed\n");
        free(content);
        return 1;
    }

    // Write the result to a new file
    char output_filename[256];
    sprintf(output_filename, "marked_%s", argv[1]);

    file = fopen(output_filename, "w");
    if (!file) {
        printf("Error: Cannot create output file\n");
        free(content);
        free(marked_content);
        return 1;
    }

    fputs(marked_content, file);

    fclose(file);
    printf("Marked content has been written to %s\n", output_filename);

    free(content);
    free(marked_content);

    return 0;
}
