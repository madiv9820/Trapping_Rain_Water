import unittest, json, os
from typing import List
from timeout_decorator import timeout
from source.python.solution import pySolution

class test_py_Solution(unittest.TestCase):
    def setUp(self):
        currentDirectory = os.path.dirname(os.path.abspath(__file__))
        filePath = os.path.join(currentDirectory, 'cases/test_cases.json')
        
        with open(
            filePath, 
            mode = "r", 
            encoding = "utf-8"
        ) as read_file: 
            self.__testcases = json.load(read_file)
            self.__solution = pySolution()

        return super().setUp()
    
    @timeout(1)
    def test(self):
        for testcase in self.__testcases:
            testName: str = testcase['name']
            height: List[int] = testcase['height']
            expectedOutput: int  = testcase['output']

            with self.subTest(testName):
                actualOutput: int = self.__solution.py_trap(height = height)
                self.assertEqual(actualOutput, expectedOutput)
        
if __name__ == '__main__': unittest.main()