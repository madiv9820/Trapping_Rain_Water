import unittest, json, os
from typing import List
from timeout_decorator import timeout  # ⏱️ Enforce time limit per test
from source.python.solution import pySolution  # 🐍 Import the pure Python solution wrapper


# 🧪 Unit tests for the Python implementation of Trapping Rain Water
class test_py_Solution(unittest.TestCase):

    def setUp(self):
        """
        📂 Load test cases from JSON file
        and initialize the Python solution wrapper.
        """
        currentDirectory = os.path.dirname(os.path.abspath(__file__))  # 📍 Directory of this test file
        filePath = os.path.join(currentDirectory, 'cases/test_cases.json')  # 📄 Path to JSON test cases
        
        # 🔓 Open and read JSON test cases
        with open(filePath, mode="r", encoding="utf-8") as read_file: 
            self.__testcases = json.load(read_file)  # 🗂️ List of test case dictionaries
            self.__solution = pySolution()           # ⚡ Initialize Python solution

        return super().setUp()
    
    @timeout(1)  # ⏱️ Each test must complete within 1 second
    def test(self):
        """
        🔄 Iterate through each test case and check the output
        """
        for testcase in self.__testcases:
            testName: str = testcase['name']        # 📝 Name of the test case
            height: List[int] = testcase['height']  # 📏 Input heights
            expectedOutput: int = testcase['output'] # 💧 Expected trapped water

            # 🔍 Use subTest for better reporting per case
            with self.subTest(testName):
                actualOutput: int = self.__solution.py_trap(height=height)
                self.assertEqual(actualOutput, expectedOutput)  # ✅ Assert correctness

# 🏁 Run tests when executed directly
if __name__ == '__main__':
    unittest.main()