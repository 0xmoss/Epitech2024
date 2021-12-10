/*
** EPITECH PROJECT, 2020
** B-CPP-300-LYN-3-1-CPPD09-
** File description:
** ex00.h
*/

#ifndef CTHULHU_H_
	#define CTHULHU_H_

    typedef struct cthulhu_s {
        int m_power;
        char *m_name;
    } cthulhu_t;

    typedef struct s_koala {
        cthulhu_t m_parent;
        char m_is_a_legend;
    } koala_t;

    cthulhu_t *new_cthulhu();
    void print_power(cthulhu_t*);
    void attack(cthulhu_t*);
    void sleeping(cthulhu_t*);

    koala_t *new_koala(char*, char);
    void eat(koala_t*);

#endif /* !CTHULHU_H_ */