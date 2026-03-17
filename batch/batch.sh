#!/bin/bash

#SBATCH -p 
#SBATCH -a 1-999 
#SBATCH -t 8:00:00
#SBATCH -J tests
#SBATCH -o /%A_%a.log
#SBATCH --exclude=

echo ${SLURMD_NODENAME}

w_nodes_dir=${1}
output_dir=${2}

#source your environment bellow:

cd ${output_dir}
time /fuck_ncx ${SLURMD_NODENAME}

if [ "$?" -eq 111 ]; then 
  touch ${w_nodes_dir}/${SLURMD_NODENAME}
fi