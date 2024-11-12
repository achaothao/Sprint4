// A Chao Thao
// Sprint 4
// 11/11/2024

#ifndef SOSGAME_H
#define SOSGAME_H

#include <wx/wx.h>
#include "SimpleGame.h"
#include "GeneralGame.h"

// All these functions are self explanatory
class SOSGame : public wxFrame
{
public:
    SOSGame(const wxString& sosgame);
    SOSGameLogic* GetGameLogic() const { return gameLogic; }

private:
    wxPanel* panel;

    // Game Mode
    wxRadioButton* simpleGameRadio;
    wxRadioButton* generalGameRadio;

    // Blue Player
    wxRadioButton* bluePlayerHuman;
    wxRadioButton* bluePlayerComputer;
    wxRadioButton* bluePlayerS;
    wxRadioButton* bluePlayerO;

    // Red Player
    wxRadioButton* redPlayerHuman;
    wxRadioButton* redPlayerComputer;
    wxRadioButton* redPlayerS;
    wxRadioButton* redPlayerO;

    wxChoice* boardSizeChoice; // Choose Board Size
    wxStaticText* currentTurn; // Display player turn
    wxButton* newGameButton; // Start a New Game
    wxStaticText* bluePlayerPoints; // Display Blue Player SOS Points
    wxStaticText* redPlayerPoints; // Display Red Player SOS Points

    vector<wxPanel*> cells;
    SOSGameLogic* gameLogic;
    int currentPlayer;
    int bluePlayerSOSCount;
    int redPlayerSOSCount;

    void CreateBoard(int size);
    void OnCellClicked(wxMouseEvent& event);
    void OnNewGame();
    void UpdateCurrentTurn();
    void UpdatePointsDisplay();
    void ResetPlayerSelections();
    void ComputerMove(); // Function for computer
    bool SimpleGameMode() const;
    bool GeneralGameMode() const;

    wxDECLARE_EVENT_TABLE();
};

#endif