#!/bin/bash

#!/bin/bash

file_with_nodes=${1}

while read node; do
  sbatch -w $node batch.sh
done < ${file_with_nodes}