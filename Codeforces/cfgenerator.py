__author__ = 'Vishal'

import fileinput
import os
import shutil

cpp_types = ["int", "float", "double", "string","long","long long", "vector<int>", "vector<string>", "vector<double>", "set<int>",
             "set<char>", "set<double>", "set<float>"]

containers = ["vector<int>", "vector<string>", "vector<double>", "set<int>", "set<char>", "set<double>", "set<float>"]
def main():
    filename = "Template.cpp"

    list = [0, 0, 0, 0, 0, 0]
    inputs = []

    # parse input file
    parse_input_file("input.txt", inputs)
    fileinput.close()

    # delete test function
    get_test_function_lines(filename, list)
    remove_test_function(filename, list)

    # remove input reader
    get_generated_code_lines(filename, list)
    remove_generated_code(filename, list)

    # generate and update cpp code
    finalvartypelist = []
    finalvarnamelist = []
    update_cpp_code(filename, inputs, list, finalvarnamelist, finalvartypelist)
    fileinput.close()

    # add test function
    start_point = get_start_point(filename, "bool double_equal")
    fileinput.close()
    add_test(filename, start_point, finalvarnamelist, finalvartypelist, inputs)
    fileinput.close()

    #and finally generate class
    start_point = get_start_point(filename, "using namespace std;")
    fileinput.close()
    generate_class(filename, start_point, finalvarnamelist, finalvartypelist, inputs)
    fileinput.close()

    #update main function for i/o
    start_point = get_start_point(filename, "Start testing")
    fileinput.close()
    update_main(filename, start_point, finalvarnamelist, finalvartypelist, inputs)
    fileinput.close()

    # rename file
    copy_rename("Template.cpp", inputs[0].split(":")[1]+".cpp")

def get_start_point(filename, start_point_text):
    for line in fileinput.input(filename, inplace=0):
        if start_point_text in line:
            return  fileinput.lineno() + 1

def get_test_function_lines(filename, list):
    for line in fileinput.input(filename, inplace=0):
        if "bool do_test" in line:
            list[2] = fileinput.lineno()

        if "return true" in line:
            list[3] = fileinput.lineno() + 1


def remove_test_function(filename, list):
    if list[2] != 0 and list[3] != 0 and list[2] - 1 != list[3]:
        for line in fileinput.input(filename, inplace=1):
            newline = line.rstrip('\r\n')
            range1 = range(list[2], list[3] + 1)
            if fileinput.lineno() not in range1:
                print(newline)
    fileinput.close()


def get_generated_code_lines(filename, list):
    for line in fileinput.input(filename, inplace=0):
        if "//start writing here" in line:
            list[0] = fileinput.lineno() + 1

        if "//end writing here" in line:
            list[1] = fileinput.lineno() - 1


def remove_generated_code(filename, list):
    if list[0] != 0 and list[1] != 0 and list[0] - 1 != list[1]:
        for line in fileinput.input(filename, inplace=1):
            newline = line.rstrip('\r\n')
            range2 = range(list[0], list[1] + 1)
            if fileinput.lineno() not in range2:
                print(newline)


def parse_input_file(filename, inputs):
    for line in fileinput.input(filename, inplace=0):
        newline = line.rstrip('\r\n')
        if fileinput.lineno() > 4:
            break
        else:
            inputs.append(newline)


def update_cpp_code(filename, inputs, list, finalvarnamelist, finalvartypelist):
    if list[0] != 0 and list[1] != 0:
        for line in fileinput.input(filename, inplace=1):
            newline = line.rstrip('\r\n')
            if fileinput.lineno() != list[0]:
                print(newline)
            else:
                input_variables = inputs[2].split(",")
                for item in input_variables:
                    vartype = item.split(":")
                    if vartype[0] == "Parameters":
                        print("        " + vartype[1] + " " + vartype[2] + ";")
                        print("        " + "from_stream(" + vartype[2] + ");")
                        finalvarnamelist.append(vartype[2])
                        finalvartypelist.append(vartype[1])

                    else:
                        print("        " + vartype[0] + " " + vartype[1] + ";")
                        print("        " + "from_stream(" + vartype[1] + ");")
                        finalvarnamelist.append(vartype[1])
                        finalvartypelist.append(vartype[0])
                print("        " + "next_line();")
                output_variables = inputs[3].split(":")
                print("        " + output_variables[1] + " __answer;")
                print("        " + "from_stream(__answer);")
                finalvarnamelist.append("__answer")
                finalvartypelist.append(output_variables[1])
                print("        cases++;")
                print("        cout << \"  Testcase #\" << cases - 1 << \" ... \";")
                conditionString = "if( do_test("
                for vars in finalvarnamelist:
                    conditionString += vars
                    conditionString += ","
                conditionString = conditionString[:-1]
                conditionString += ")) {"
                print("        " + conditionString)
                print("            " + "passed++;")
                print("        }")
                print("        //end writing here")


def add_test(filename, start_point, finalvarnamelist, finalvartypelist, inputs):
    for line in fileinput.input(filename, inplace=1):
        newline = line.rstrip('\r\n')
        if fileinput.lineno() == start_point :
            print(newline)
            append_test_function(finalvarnamelist, finalvartypelist, inputs)
        else:
            print(newline)


def append_test_function(finalvarnamelist, finalvartypelist, inputs):
    function_name = "bool do_test("
    for (vartype, varname) in zip(finalvartypelist, finalvarnamelist):
        function_name = function_name + vartype + " " + varname + ","
    function_name = function_name[:-1]
    function_name += ") {"
    print(function_name)
    classname = inputs[0].split(":")[1]
    methodname = inputs[1].split(":")[1]
    print(" " * 4 + classname + " *instance = new " + classname + "();" )
    print(" " * 4 + finalvartypelist[len(finalvartypelist)-1] + " __result = instance->" + methodname + "(" + ", ".join(finalvarnamelist[:-1]) + ");")
    print(" " * 4 + "delete instance;")
    print(" " * 4 + "if (__answer == __result ) {")
    print(" " * 8 + "cout << \"PASSED!\" << endl;")
    print(" " * 8 + "return true;")
    print(" " * 4 + "}")
    print(" " * 4 + "else {")
    print(" " * 8 + "cout << \"FAILED!\" << endl;")
    print(" " * 8 + "cout << \"           Expected: \" << to_string(__answer) << endl;")
    print(" " * 8 + "cout << \"           Received: \" << to_string(__result) << endl;")
    print(" " * 8 + "return false;")
    print(" " * 4 + "}")
    print(" " * 4 + "return true;")
    print("}")


def generate_class(filename, start_point, finalvarnamelist, finalvartypelist, inputs):
    for line in fileinput.input(filename, inplace=1):
        newline = line.rstrip('\r\n')
        if fileinput.lineno() == start_point:
            print(newline)
            write_class(finalvarnamelist, finalvartypelist, inputs)
        else:
            print(newline)


def write_class(finalvarnamelist, finalvartypelist, inputs):
    classname = inputs[0].split(":")[1]
    methodname = inputs[1].split(":")[1]
    print("class " + classname + " {")
    print("public:")
    function_args = ""
    for (vartype, varname) in zip(finalvartypelist[:-1], finalvarnamelist[:-1]):
        function_args = function_args + vartype + " " + varname + ", "
    function_args = function_args[:-2]
    print(" " * 4 + finalvartypelist[len(finalvartypelist)-1] + " " + methodname + "("+function_args+") {")
    return_val = " " * 8 + "return "
    return_type = finalvartypelist[-1]
    if return_type == "string":
        return_val += "\" \";"
    if return_type == "int":
        return_val += "0;"
    if return_type == "double":
        return_val += "0.0;"
    if return_type == "float":
        return_val += "0.0;"
    if return_type == "vector<int>":
        return_val += "vector<int>();"
    if return_type == "vector<char>":
        return_val += "vector<char>();"
    if return_type == "vector<double>":
        return_val += "vector<double>();"
    if return_type == "long":
        return_val += "0;"
    if return_type == "long long":
        return_val += "0;"
    print(return_val)
    print(" " * 4 + "}")
    print("};")


def update_main(filename, start_point, finalvarnamelist, finalvartypelist, inputs):
    for line in fileinput.input(filename, inplace=1):
        newline = line.rstrip('\r\n')
        if fileinput.lineno() == start_point:
            print(newline)
            append_main(finalvarnamelist, finalvartypelist, inputs)
        else:
            print(newline)


def append_main(finalvarnamelist, finalvartypelist, inputs):
    print(" " * 4 + "//start input for on line judge")
    for (vartype, varname) in zip(finalvartypelist[:-1], finalvarnamelist[:-1]):
        if vartype not in containers:
            if vartype == "string":
                print(" " * 4 + "string " + varname + " = getStringInput();")
            else:
                print(" " * 4 + vartype + " " + varname + " ;")
                print(" " * 4 + "cin >> " + varname + " ;")
        else:
            print(" " * 4 + "cout << \"enter no of elements :\";")
            print(" " * 4 + "int " + "size_" + varname + " ;")
            print(" " * 4 + "getUserInput(size_input);")
            print(" " * 4 + vartype + " " + varname + " ;")
            print(" " * 4 + "for ( int i = 0 ; i < "+"size_" + varname + " ; i++ ) {")
            element_type = vartype.split("<")[1][:-1]
            if element_type == "string":
                print(" " * 8 + "cout << \"enter \" << i << \"th " + element_type + " :\";")
                print(" " * 8 + "string input_var = getStringInput();;")
            else:
                print(" " * 8 + "cout \"<< enter \" << i << \"th " + element_type + " :\";")
                print(" " * 8 + element_type + " " + "input_var ;")
                print(" " * 8 + "cin >> " + "input_var ;")
            print(" " * 8 + varname + ".push_back( input_var ) ;")
            print(" " * 4 + "}")
    print(" " * 8 + "//calling class")
    classname = inputs[0].split(":")[1]
    methodname = inputs[1].split(":")[1]
    print(" " * 4 + classname + " *instance = new " + classname + "() ;")
    print(" " * 4 + finalvartypelist[len(finalvartypelist)-1] + " __result = instance->" + methodname + "(" + ", ".join(finalvarnamelist[:-1]) + ");")
    print(" " * 4 + "cout << __result ;")
    print(" " * 4 + "delete instance;")
    print(" " * 4 + "//end input for on line judge")


def copy_rename(old_file_name, new_file_name):
        src_dir= os.curdir
        dst_dir= os.path.join(os.curdir, "subfolder")
        src_file = os.path.join(src_dir, old_file_name)
        shutil.copy(src_file,dst_dir)

        dst_file = os.path.join(dst_dir, old_file_name)
        new_dst_file_name = os.path.join(dst_dir, new_file_name)
        os.rename(dst_file, new_dst_file_name)
        shutil.copy(new_dst_file_name, os.curdir)
        os.remove(new_dst_file_name)

main()