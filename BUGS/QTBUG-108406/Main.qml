import QtQml

QtObject
{
    property list<int> intList: [1, 2, 3, 4]
    // Component.onCompleted:
    // {
    //     console.log("int:", intList[2])
    // }
    property list<QtObject> objectList :[
        QtObject { objectName: "obj1" },
        QtObject { objectName: "obj2" },
        QtObject { objectName: "obj3" }]
    Component.onCompleted: {
        for (let i = 0; i < objectList.length; ++i) {
            console.log("Object", i, "name:", objectList[i].objectName);
        }
    }
}

