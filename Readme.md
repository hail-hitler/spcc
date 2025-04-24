# SPCC Experiments README


## 1. Code Generator

**Files Needed:**
- `code_gen.c`
- `coded_gen_input.txt`

**Execution Commands:**
```bash
gcc code_gen.c -o code_gen
./code_gen
```

This program reads assembly-like instructions from `coded_gen_input.txt` and converts them to machine-like instructions, writing the output to `output.txt`.

## 2. Code Optimizer

**Files Needed:**
- `code_optimize.c`

**Execution Commands:**
```bash
gcc code_optimize.c -o code_optimize
./code_optimize
```

This program performs dead code elimination and common subexpression elimination on intermediate code entered by the user.

## 3. Lexical Analyzer

**Files Needed:**
- `lexical_analyser.c`
- `lexical_analyser.txt` (or any input file)

**Execution Commands:**
```bash
gcc lexical_analyser.c -o lexical_analyser
./lexical_analyser
# When prompted, enter the filename: lexical_analyser.txt
```

This program analyzes the input file and identifies tokens, delimiters, and operators.

## 4. Macro Processor

**Files Needed:**
- `macro.c`
- `macin.dat` (input)

**Execution Commands:**
```bash
gcc macro.c -o macro
./macro
```

The program processes macros in the input file and generates `macout.dat` and `deftab.dat`.

## 5. Operator Precedence Parser

**Files Needed:**
- `operator_pres.c`

**Execution Commands:**
```bash
gcc operator_pres.c -o operator_pres
./operator_pres
# Enter an expression when prompted (e.g., i+i*i)
```

This program parses expressions using operator precedence relations.

## 6. Shift-Reduce Parser

**Files Needed:**
- `sr_parser.c`

**Execution Commands:**
```bash
gcc sr_parser.c -o sr_parser
./sr_parser
# Enter an input string when prompted (e.g., id+id*id)
```

This program implements a shift-reduce parser for a simple grammar.

## 7. Flex Lexical Analyzer

**Files Needed:**
- `grammar.l`

**Execution Commands:**
```bash
lex grammar.l
gcc lex.yy.c -ll
./a.out
# Type input text and press Enter
```

This program uses Flex to generate a lexical analyzer for a simple grammar.

## 8. Yacc/Bison Calculator

**Files Needed:**
- `test.l` (Lex file)
- `test.y` (Yacc file)

**Execution Commands:**
```bash
lex test.l
bison -dy test.y
gcc lex.yy.c y.tab.c -w
./a.out
# Enter arithmetic expressions when prompted
```

This program implements a calculator that evaluates arithmetic expressions.

## 9. Two-Pass Assembler

**Files Needed:**
- `two_pass_assembler.c`

**Execution Commands:**
```bash
gcc two_pass_assembler.c -o two_pass_assembler
./two_pass_assembler
```

This program demonstrates a simplified two-pass assembler with symbol table and base table generation.

