#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "ft_isalnum.c"
#include "ft_isdigit.c"
#include "ft_isalpha.c"
#include "ft_memset.c"
#include "ft_isascii.c"
#include "ft_isprint.c"
#include "ft_strlen.c"
#include "ft_bzero.c"
#include "ft_memcpy.c"
#include "ft_strlcpy.c"
#include "ft_strlcat.c"
#include "ft_toupper.c"
#include "ft_tolower.c"
#include "ft_strchr.c"
#include "ft_strrchr.c"
#include "ft_strncmp.c"
#include "ft_memchr.c"
#include "ft_memcmp.c"
<<<<<<< Updated upstream

#include "ft_atoi.c"
#include "ft_calloc.c"
#include "ft_strdup.c"
#include "ft_substr.c"
=======
>>>>>>> Stashed changes

void test_ft_isalpha() {
    printf("TEST IS_ALPHA ");
    int my_counter = 0;
    int true_counter = 0;
    for (int i=0; i<200; i++){
        if (isalpha(i) == 1) {
            true_counter++;
        }
        if (ft_isalpha(i) == 1) {
            my_counter++;
        }
    }
    if (true_counter == my_counter) {
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
        printf("True counter: %i\n",true_counter);
        printf("ft counter: %i\n",my_counter);
    }
}

void test_ft_isdigit() {
    printf("TEST IS_DIGIT ");
    int my_counter = 0;
    int true_counter = 0;
    for (int i=0; i<200; i++){
        if (isdigit(i) == 1) {
            true_counter++;
            //printf("%i\n", i);
        }
        if (ft_isdigit(i) == 1) {
            my_counter++;
        }
    }
    if (true_counter == my_counter) {
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
        printf("True counter: %i\n",true_counter);
        printf("ft counter: %i\n",my_counter);
    }
}

void test_ft_isalnum() {
    printf("TEST IS_ALNUM ");
    int my_counter = 0;
    int true_counter = 0;
    for (int i=0; i<200; i++){
        if (isalnum(i) == 1) {
            true_counter++;
            //printf("%i\n", i);
        }
        if (ft_isalnum(i) == 1) {
            my_counter++;
        }
    }
    if (true_counter == my_counter) {
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
        printf("True counter: %i\n",true_counter);
        printf("ft counter: %i\n",my_counter);
    }
}

void test_ft_isascii() {
    printf("TEST IS_ASCII ");
    int my_counter = 0;
    int true_counter = 0;
    for (int i=0; i<200; i++){
        if (isascii(i) == 1) {
            true_counter++;
            //printf("%i\n", i);
        }
        if (ft_isascii(i) == 1) {
            my_counter++;
            //printf("%i\n", i);
        }
    }
    if (true_counter == my_counter) {
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
        printf("True counter: %i\n",true_counter);
        printf("ft counter: %i\n",my_counter);
    }
}

void test_ft_isprint() {
    printf("TEST IS_PRINT ");
    int my_counter = 0;
    int true_counter = 0;
    for (int i=0; i<200; i++){
        if (isprint(i) == 1) {
            true_counter++;
            //printf("%i\n", i);
        }
        if (ft_isprint(i) == 1) {
            my_counter++;
            //printf("%i\n", i);
        }
    }
    if (true_counter == my_counter) {
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
        printf("True counter: %i\n",true_counter);
        printf("ft counter: %i\n",my_counter);
    }
}


void test_ft_strlen() {
    printf("TEST STRLEN   ");
    char* str = "almoststaqe4";
    if (strlen(str) == ft_strlen(str)){
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
    }
    return;
}

void test_ft_memset() {
    printf("TEST MEMSET   ");
    char str[10] = "almost";
	ft_memset(str, '-', 3);
    //printf("%s", (char *)str);
    if (strcmp(str, "---ost") == 0){
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
    }
    return;
}

void test_ft_bzero() {
    printf("TEST BZERO    ");
    char str[4];
    char str_cpy[4];
    size_t n = 4;
    bzero(str, n);
	ft_bzero(str_cpy, n);
    printf("%s", (char *)str);
    printf("%s", (char *)str_cpy);
	if (strcmp(str, str_cpy) == 0){
		printf("\033[0;32m"); //Set the text to the color green
		printf("PASS\n");
		printf("\033[0m"); //Resets the text to default color
	} else {
		printf("\033[0;31m"); //Set the text to the color red
		printf("ERROR!\n");
		printf("\033[0m"); //Resets the text to default color
	}
    return;
}

void test_ft_memcpy() {
	printf("TEST MEMCPY   ");
	void *dst[5];
	void *dst_cpy[5];
	void *src = "hola";
	void *src_cpy = "hola";
	size_t n = 2;
	ft_memcpy(dst, src, n);
	memcpy(dst_cpy, src_cpy, n);
	//printf("\n%s", (char *)dst);
	//printf("\n%s", (char *)dst_cpy);
	if (strcmp((char *)dst, "ho") == 0){
		printf("\033[0;32m"); //Set the text to the color green
		printf("PASS\n");
		printf("\033[0m"); //Resets the text to default color
	} else {
		printf("\033[0;31m"); //Set the text to the color red
		printf("ERROR!\n");
		printf("\033[0m"); //Resets the text to default color
	}
	return;
}

void test_ft_strlcpy() {
	printf("TEST STRLCPY  ");
	char src[] = "Hello there, Venus";
	char src_cpy[] = "Hello there, Venus";
	char dst[19];
	char dst_cpy[19];
	strlcpy(dst,src,2);
	ft_strlcpy(dst_cpy,src_cpy,2);
	//printf("\n%s", (char *)dst);
	//printf("\n%s\n", (char *)dst_cpy);
	if (strcmp(dst, dst_cpy) == 0) {
		printf("\033[0;32m"); //Set the text to the color green
		printf("PASS\n");
		printf("\033[0m"); //Resets the text to default color
	} else {
		printf("\033[0;31m"); //Set the text to the color red
		printf("ERROR!\n");
		printf("\033[0m"); //Resets the text to default color
	}
	return;
}

void test_ft_strlcat() {
	printf("TEST STRLCAT  ");


	char dst[10] = "1234";
	char src[10] = "ABCD";
	char dst_cpy[10] = "1234";
	char src_cpy[10] = "ABCD";

	strlcat(dst, src, 7);
	ft_strlcat(dst_cpy, src_cpy, 7);
	if (strcmp(dst, dst_cpy) == 0) {
		printf("\033[0;32m"); //Set the text to the color green
		printf("PASS\n");
		printf("\033[0m"); //Resets the text to default color
	} else {
		printf("\033[0;31m"); //Set the text to the color red
		printf("ERROR!\n");
		printf("\033[0m"); //Resets the text to default color
	}
	return;
}

void test_ft_toupper() {
	printf("TEST TOUPPER  ");

	char *str = "a1b2C3D 4z";
	char *str_cpy = "a1b2C3D 4z";
	char str_upper[10];
	char str_upper_cpy[10];
	while(*str) {
		*str_upper = toupper(*str);
		*str_upper_cpy = ft_toupper(*str_cpy);
		str++;
		str_cpy++;
		if (*str_upper != *str_upper_cpy) {
			printf("\033[0;31m"); //Set the text to the color red
			printf("ERROR!\n");
			printf("\033[0m"); //Resets the text to default color
		}
	}
	printf("\033[0;32m"); //Set the text to the color green
	printf("PASS\n");
	printf("\033[0m"); //Resets the text to default color
	return;
}

void test_ft_tolower() {
	printf("TEST TOLOWER  ");

	char *str = "a1b2C3D 4z";
	char *str_cpy = "a1b2C3D 4z";
	char str_lower[10];
	char str_lower_cpy[10];
	while(*str) {
		*str_lower = tolower(*str);
		*str_lower_cpy = ft_tolower(*str_cpy);
		str++;
		str_cpy++;
		if (*str_lower != *str_lower_cpy) {
			printf("\033[0;31m"); //Set the text to the color red
			printf("ERROR!\n");
			printf("\033[0m"); //Resets the text to default color
		}
	}
	printf("\033[0;32m"); //Set the text to the color green
	printf("PASS\n");
	printf("\033[0m"); //Resets the text to default color
	return;
}

void test_ft_strchr() {
	printf("TEST STRCHR   ");
	char *str_cpy = "a1b2C3D 4z";

	if (strcmp(ft_strchr(str_cpy, 'D'), strchr(str_cpy, 'D')) == 0) {
		printf("\033[0;32m"); //Set the text to the color green
		printf("PASS\n");
		printf("\033[0m"); //Resets the text to default color
	} else {
		printf("\033[0;31m"); //Set the text to the color red
		printf("ERROR!\n");
		printf("\033[0m"); //Resets the text to default color
	}
	return;
}

void test_ft_strrchr() {
	printf("TEST STRRCHR  ");
	char *str_cpy = "a1b2C3D 4z";
	if (strcmp(ft_strrchr(str_cpy, 'D'), strrchr(str_cpy, 'D')) == 0) {
		printf("\033[0;32m"); //Set the text to the color green
		printf("PASS\n");
		printf("\033[0m"); //Resets the text to default color
	} else {
		printf("\033[0;31m"); //Set the text to the color red
		printf("ERROR!\n");
		printf("\033[0m"); //Resets the text to default color
	}
	return;
}

void test_ft_strncmp() {
	printf("TEST STRNCMP  ");
	void *s1 = "hola";
	void *s2 = "hola";
	if (ft_strncmp(s1, s2, 3) == strncmp(s1, s2, 3)) {
		printf("\033[0;32m"); //Set the text to the color green
		printf("PASS\n");
		printf("\033[0m"); //Resets the text to default color
	} else {
		printf("\033[0;31m"); //Set the text to the color red
		printf("ERROR!\n");
		printf("\033[0m"); //Resets the text to default color
	}
	return;
}

void test_ft_memchr() {
	printf("TEST MEMCHR   ");
	char *str_cpy = "a1b2C3D 4z";

	if (strcmp(ft_memchr(str_cpy, 'D', 10), memchr(str_cpy, 'D', 10)) == 0) {
		printf("\033[0;32m"); //Set the text to the color green
		printf("PASS\n");
		printf("\033[0m"); //Resets the text to default color
	} else {
		printf("\033[0;31m"); //Set the text to the color red
		printf("ERROR!\n");
		printf("\033[0m"); //Resets the text to default color
	}
	return;
}

void test_ft_memcmp() {
	printf("TEST MEMCMP   ");
	char *str1 = "a1b2C3D 4z";
	char *str2 = "a1b2C3D 4a";

	if (ft_memcmp(str1, str2, 10) == memcmp(str1, str2, 10)) {
		printf("\033[0;32m"); //Set the text to the color green
		printf("PASS\n");
		printf("\033[0m"); //Resets the text to default color
	} else {
		printf("\033[0;31m"); //Set the text to the color red
		printf("ERROR!\n");
		printf("\033[0m"); //Resets the text to default color
	}
	return;
}

void test_ft_atoi() {
    printf("TEST ATOI     ");
    char *str = "   294 2 a76";

    //printf("\n%i\n", atoi(str));
    //printf("%i", ft_atoi(str));

    if (atoi(str) == ft_atoi(str)) {
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
    }
    return;
}

void test_ft_calloc() {
    printf("TEST CALLOC   ");
    //printf("\n%c\n", (char *)calloc(1, sizeof(char)));
    //printf("\n%c\n", (char *)ft_calloc(1, sizeof(char)));
    if (strcmp(calloc(1, sizeof(char)), ft_calloc(1, sizeof(char))) == 0) {
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
    }
    return;
}

void test_ft_strdup() {
    printf("TEST STRDUP   ");
    char * str = "buenas";
    //printf("\n%s\n", strdup(str));
    //printf("\n%s\n", ft_strdup(str));
    if (strcmp(ft_strdup(str), strdup(str)) == 0) {
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
    }
    return;
}

void test_ft_substr() {
    printf("TEST SUBSTR   ");
    char * str = "buenas";
    //printf("\n%s\n", ft_substr(str, 'e', 6));

    if (strcmp(ft_substr(str, 'e', 6), "enas") == 0) {
        printf("\033[0;32m"); //Set the text to the color green
        printf("PASS\n");
        printf("\033[0m"); //Resets the text to default color
    } else {
        printf("\033[0;31m"); //Set the text to the color red
        printf("ERROR!\n");
        printf("\033[0m"); //Resets the text to default color
    }
    return;
}
void test_ft_strnstr() {
	printf("TEST STRNSTR   ");
	char *str1 = "a1b2C3D 4z";
	char *str2 = "a1b2C3D 4a";

	if (ft_memcmp(str1, str2, 10) == memcmp(str1, str2, 10)) {
		printf("\033[0;32m"); //Set the text to the color green
		printf("PASS\n");
		printf("\033[0m"); //Resets the text to default color
	} else {
		printf("\033[0;31m"); //Set the text to the color red
		printf("ERROR!\n");
		printf("\033[0m"); //Resets the text to default color
	}
	return;
}



int main(void) {
    test_ft_isalpha();
    test_ft_isdigit();
    test_ft_isalnum();
    test_ft_isascii();
    test_ft_isprint();
    test_ft_strlen(); //#TODO: Add more tests
    test_ft_memset(); //#TODO: Add more tests
    test_ft_bzero();  //#TODO: Add more tests
	test_ft_memcpy(); //#TODO: Verificar..
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_strchr();
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();// #TODO: Validate NULL
	test_ft_memcmp();
    test_ft_atoi();
    test_ft_calloc();
    test_ft_strdup();
    test_ft_substr();

	test_ft_strnstr();
    return 0;
}
