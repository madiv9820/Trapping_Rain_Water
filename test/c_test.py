import unittest, json, os
from typing import List
from timeout_decorator import timeout  # ⏱️ Enforce time limit per test
from source.c.solution import cSolution  # 🧩 Import your Cython C wrapper


# 🧪 Unit tests for the C implementation of Trapping Rain Water
class test_c_Solution(unittest.TestCase):

    def setUp(self):
        """
        📂 Load test cases from JSON file
        and initialize the C solution wrapper.
        """
        currentDirectory = os.path.dirname(os.path.abspath(__file__))  # 📍 Directory of this test file
        filePath = os.path.join(currentDirectory, 'cases/test_cases.json')  # 📄 JSON test cases path
        
        # 🔓 Open and read JSON test cases
        with open(filePath, mode="r", encoding="utf-8") as read_file: 
            self.__testcases = json.load(read_file)  # 🗂️ List of test case dicts
            self.__solution = cSolution()            # ⚡ Initialize C solution

        return super().setUp()
    
    @timeout(1)  # ⏱️ Each test must complete within 1 second
    def test(self):
        """
        🔄 Iterate through each test case and check output
        """
        for testcase in self.__testcases:
            testName: str = testcase['name']       # 📝 Name of the test case
            height: List[int] = testcase['height'] # 📏 Input heights
            expectedOutput: int = testcase['output'] # 💧 Expected trapped water

            # 🔍 Use subTest for better reporting per case
            with self.subTest(testName):
                actualOutput: int = self.__solution.c_trap(height = height)
                self.assertEqual(actualOutput, expectedOutput)  # ✅ Assert correctness
        
# 🏁 Run tests when executed directly
if __name__ == '__main__':
    unittest.main()