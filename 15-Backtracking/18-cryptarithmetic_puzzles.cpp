bool ExhaustiveSolve(puzzleT puzzle, string lettersToAssign){
    if (lettersToAssign.empty())
        return PuzzleSolved(puzzle); 
    for (int digit = 0; digit <= 9; digit++) {
        if (AssignLetterToDigit(lettersToAssign[0], digit)){
            if (ExhaustiveSolve(puzzle, lettersToAssign.substr(1)))
                return true;
            UnassignLetterFromDigit(lettersToAssign[0], digit);
        }
    }
    return false; 
}