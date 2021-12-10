#ifndef _TABLE_HPP_
    #define _TABLE_HPP_

    class Table
    {
        public:
            Table();
            ~Table();

            bool and_gate(bool, bool);
            bool or_gate(bool, bool);
            bool nor_gate(bool, bool);
            bool nand_gate(bool, bool);
            bool xor_gate(bool, bool);
            int sum_gate(bool, bool);
            bool not_gate(bool, bool);
    };

#endif /* _NANOTEKSPICE_HPP_ */