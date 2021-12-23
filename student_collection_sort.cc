#include "student_collection.cpp"

// int compareStudentRecord(const void *a, const void *b)
// {
//     StudentRecord *recordA = (StudentRecord *)a;
//     StudentRecord *recordB = (StudentRecord *)b;
//     if (recordA->grade() == -1 || recordB->grade() == -1)
//         return 0;
//     return recordA->grade() - recordB->grade();
// }

int compareStudentRecord(const void *voidA, const void *voidB)
{
    StudentRecord *recordA = (StudentRecord *)voidA;
    StudentRecord *recordB = (StudentRecord *)voidB;
    return recordA->grade() - recordB->grade();
}

int main(int argc, char const *argv[])
{
    // StudentRecord students[20];
    // int lenItems = 20;

    // for (int i = 0; i < lenItems - 1; ++i) {
    //     if (students[i].grade() != -1) {
    //         for (int j = i + 1; j < lenItems; ++j) {
    //             if (students[j].grade() != -1 &&
    //                 students[j].grade() < students[i].grade()) {
    //                 StudentRecord tmp = students[i];
    //                 students[i] = students[j];
    //                 students[j] = tmp;
    //             }
    //         }
    //     }
    // }

    StudentRecord r(10, 1, "one");
    StudentRecord r2(-1, -1, "");
    StudentRecord r3(20, 2, "two");
    StudentRecord r4(-1, -1, "");
    StudentRecord r5(30, 3, "three");
    StudentRecord r6(40, 4, "four");
    StudentRecord r7(-1, -1, "");

    int arraySize = 7;
    StudentRecord sra[arraySize] = {r6, r3, r2, r4, r, r5, r7};
    StudentRecord sortArray[arraySize];
    int sortArrayCount = 0;
    for (int i = 0; i < arraySize; i++) {
        if (sra[i].grade() != -1) {
            sortArray[sortArrayCount] = sra[i];
            sortArrayCount++;
        }
    }
    qsort(sortArray, sortArrayCount, sizeof(StudentRecord),
          compareStudentRecord);
    sortArrayCount = 0;
    for (int i = 0; i < arraySize; i++) {
        if (sra[i].grade() != -1) {
            sra[i] = sortArray[sortArrayCount];
            sortArrayCount++;
        }
    }
    std::cout << "";
    // int arrSize = 7;
    // StudentRecord items[arrSize] = {r6, r3, r2, r4, r, r5, r7};
    // StudentRecord sortArray[arrSize];
    // int sortArrayCount = 0;
    // for (int i = 0; i < arrSize; ++i) {
    //     if (items[i].grade() != -1) {
    //         sortArray[sortArrayCount] = items[i];
    //         ++sortArrayCount;
    //     }
    // }

    // qsort(sortArray, arrSize, sizeof(StudentRecord), compareStudent);

    // // TODO munmap_chunk(): invalid pointer
    // int sortArrayPos = 0;
    // for (int i = 0; i < arrSize; ++i) {
    //     if (items[i].grade() != -1) {
    //         items[i] = sortArray[sortArrayPos];
    //         ++sortArrayPos;
    //     }
    // }

    // std::cout << "";
}
