data Answer = Yes Int | No Int | Unknown deriving (Show, Eq)
type Test = [Answer]
type Exam = [Test]

valueOfAnswer :: Answer -> Int
valueOfAnswer (Yes n) = n
valueOfAnswer (No n) = -n
valueOfAnswer (Unknown) = 0

testScore :: Test -> Int
testScore test = sum [valueOfAnswer answer | answer <- test]

averageScore :: Exam -> Double
averageScore exam = (fromIntegral(sumAllTestScores exam)) / (fromIntegral(length exam))

sumAllTestScores :: Exam -> Int
sumAllTestScores exam = sum [testScore test | test <- exam]

aboveLimit :: Int -> Exam -> Int
aboveLimit limit exam = length [test | test <- exam, testScore test >= limit]

highestScore :: Exam -> Test
highestScore (test1:tests) = highestScoreHelper test1 tests

highestScoreHelper :: Test -> Exam -> Test
highestScoreHelper test [] = test
highestScoreHelper test (test2:tests)
	| (testScore test) < (testScore test2) = highestScoreHelper test2 tests
	| otherwise = highestScoreHelper test tests

exampleTest1 :: Test
exampleTest1 = [Yes 5, No 3, Unknown, Yes 2, No 1, Yes 3, Yes 2, No 1, Unknown]

exampleTest2 :: Test
exampleTest2 = [Yes 5, Yes 5, Yes 5, No 5, Unknown]

exampleExam :: Exam
exampleExam = [exampleTest1, exampleTest2]