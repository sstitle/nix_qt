#include <iostream>
#include <BRepPrimAPI_MakeBox.hxx>
#include <TopoDS_Shape.hxx>
#include <BRepTools.hxx>

int main() {
    // Create a simple box using OpenCASCADE
    double length = 100.0;
    double width = 50.0;
    double height = 25.0;

    // Create the box shape
    TopoDS_Shape box = BRepPrimAPI_MakeBox(length, width, height).Shape();

    // Output the box shape to a file
    if (!BRepTools::Write(box, "box.brep")) {
        std::cerr << "Error: Unable to write the box shape to file." << std::endl;
        return 1;
    }

    std::cout << "Box shape created and written to 'box.brep' successfully." << std::endl;
    return 0;
}
