# Check for the input file
if [ $# -eq 0 ]
  then
    echo "No input file specified"
    exit 1
fi

# Get the input file name
input_file="$1"
base_name=$(basename "$input_file" .c)

# Generate .ll file
clang -S -emit-llvm -Xclang -disable-O0-optnone "$input_file"

# Perform optimization
opt -S -O3 "${base_name}.ll" -o "${base_name}_opt_O3.ll"

# Generate assembly file
llc "${base_name}_opt_O3.ll" -o "${base_name}_opt_llvm_O3.s"

# Generate object files
as --64 -o "${base_name}_opt_llvm_as_O3.o" "${base_name}_opt_llvm_O3.s"
as --64 start.s -o start.o
ld start.o "${base_name}_opt_llvm_as_O3.o" -o "${base_name}_opt_llvm_as_O3" -dynamic-linker /lib64/ld-linux-x86-64.so.2 -lc

# Run the output
./"${base_name}_opt_llvm_as_O3"