# analysis_cisregulatory_elements

This code and project aims to analyse long genome sequences for positions and number of occurences of co-occurring cis regulatory elements which will help us identify the promoter regions at various spacer lengths.
This study of promotor regions is crucial for development of biotechnological applications to manipulate promoter regions for production of geneticaly modified plants.

**1. Skeleton_code**:

Run the skeleton code with a fasta file of the genome you want to analyse.

The code will ask you for two sequences between which the distances, occurences and positions have to be analysed.

This will create a csv file named output2 that holds all the data of your interest.

**2. csvanalyse.cpp**:

Running this code will give you a visual representation- a frequency table of the data with frequency of occurences at every spacer length from 0-25 between the given two sequences.

**NOTE:**
**There are two common formats that are widely used to store- FASTQ and FNA.
If your raw date genome file is in the FNA format then you can directly proceed with running the skeleton code.
If your raw data genome file is in the FASTQ format then run the *convertfastq-fna.cpp* code that will convert your FASTQ file to FNA file. Then you can proceed with the skeleton code and following steps.**
