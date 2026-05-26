/**
 * ProClubsSeasons.h
 *
 * Header file for Pro Clubs Season Management System
 * Manages players, facilities, and objectives for a football club season
 */


#ifndef PROCLUBSSEASON_H
#define PROCLUBSSEASON_H

#include <string>
#include <vector>

// Forward declarations to avoid circular dependencies

class ProClubsSeasons;
class Player;
class Captain;
class PlayerAttributes;
class PlayerPosition;
class Facilities;
class Medical;
class Tactical;
class Training;
class Objectives;
class ClubAmbitions;
class PlayerChallenges;
class LeaguePosition;

/**
 * ProClubsSeasons Class
 *
 * Main class representing a Pro Clubs season management system.
 * Manages the collection of players, facilities, and objectives for the season.
 */


class ProClubsSeasons
{
public:

    // Constructor and destructor

    ProClubsSeasons();
    ~ProClubsSeasons();

    /**
     * Check if all facilities have been upgraded
     * @return true if facilities are upgraded, false otherwise
     */


    bool upgraded();

    /**
     * Check if all season objectives are complete
     * @return true if season is complete, false otherwise
     */

    bool isComplete();
protected:
private:
    std::vector<Player*> players; // Collection of all players in the club

    std::vector<Facilities*> facilities;  // Collection of club facilities

    std::vector<Objectives*> objectives; // Collection of season objectives

};

/**
 * Objectives Class (Abstract Base Class)
 *
 * Base class for various types of objectives in the season.
 * Provides common interface for checking completion status.
 */

class Objectives
{
public:

    // Constructor and virtual destructor for proper polymorphic deletion

    Objectives();
    virtual ~Objectives();

    /**
     * Check if the objective is complete
     * @return true if complete, false otherwise
     */

    bool isComplete() const;

    /**
     * Set the completion status of the objective
     * @param completed The new completion status
     */

    void setComplete(bool completed);

    /**
     * Pure virtual function to check and update completion status
     * Must be implemented by derived classes
     */

    virtual void checkComplete() = 0;
protected:
    bool completed; // Tracks whether this objective has been completed


private:

};

class ClubAmbitions : public Objectives
{
public:
    /**
 * ClubAmbitions Class
 *
 * Represents club-wide ambitions and goals for the season.
 * Examples: Win the league, qualify for tournaments, etc.
 */

    ClubAmbitions();
    ~ClubAmbitions();

    /**
     * Check if club ambitions have been met
     * Overrides base class pure virtual function
     */


    void checkComplete() override;


protected:
private:
};

/**
 * PlayerChallenges Class
 *
 * Represents individual player challenges and milestones.
 * Examples: Score X goals, maintain clean sheets, etc.
 */

class PlayerChallenges : public Objectives
{
public:
    PlayerChallenges();
    ~PlayerChallenges();

    /**
     * Check if player challenges have been completed
     * Overrides base class pure virtual function
     */

    void checkComplete() override;

protected:
private:
};

/**
 * LeaguePosition Class
 *
 * Represents objectives related to league standing and position.
 * Tracks the target division/field and completion status.
 */

class LeaguePosition : public Objectives
{
public:
    LeaguePosition();
    ~LeaguePosition();

    /**
     * Get the target field/division for this objective
     * @return The field/division name as a string
     */

    std::string getField() const;

    /**
     * Set the target field/division for this objective
     * @param fieldType The name of the target field/division
     */

    void setField(const std::string & fieldType);

    /**
     * Check if league position objective has been achieved
     * Overrides base class pure virtual function
     */

    void checkComplete() override;

protected:
private:
    std::string field;

};

/**
 * Facilities Class (Abstract Base Class)
 *
 * Base class for all club facilities (Medical, Training, Tactical).
 * Provides common interface for facility management and upgrades.
 */

class Facilities
{
public:
    Facilities();
    virtual ~Facilities();

    /**
     * Get the name of this facility
     * @return The facility name as a string
     */

    std::string getNameOfFacility();

    /**
     * Check if this facility has been upgraded
     * @return true if upgraded, false otherwise
     */

    bool isUpgraded() const;

    /**
     * Set the name of this facility
     * @param name The new facility name
     */

    void setNameOfFacility(const std::string & name);

    /**
     * Set the upgrade status of this facility
     * @param status The new upgrade status
     */


    void setUpgraded(bool status);

    /**
     * Pure virtual function to check upgrade status
     * Must be implemented by derived classes
     * @return true if upgraded, false otherwise
     */


    virtual bool upgraded() = 0;

protected:
    bool upgraded;
    std::string nameOfFacility;
private:
};
/**
 * Medical Class
 *
 * Represents the club's medical facilities.
 * Affects player injury rates and recovery times.
 * Better facilities reduce injury risk and speed up recovery.
 */

class Medical : public Facilities
{
public:
    Medical();
    ~Medical();

    /**
     * Get the current chance of player injury
     * @return Injury probability as a float (0.0 to 1.0)
     */

    float getChancesOfInjury() const;

    /**
     * Get the current recovery rate for injured players
     * @return Recovery rate as a float
     */

    float getRecoveryRate() const;

    /**
     * Set the chance of player injury
     * @param chances New injury probability
     */

    void setChancesOfInjury(float chances);
    /**
     * Set the recovery rate for injured players
     * @param rate New recovery rate
     */

    void setRecoveryRate(float rate);

    /**
     * Check if medical facilities are upgraded
     * Overrides base class pure virtual function
     * @return true if upgraded, false otherwise
     */

    bool upgraded() override;

protected:
private:
    float chancesOfInjury;
    // Probability of player getting injured (lower is better)
    float recoveryRate;
    // Rate at which players recover from injuries (higher is better)
};

/**
 * Training Class
 *
 * Represents the club's training facilities.
 * Affects the rate at which players improve their attributes.
 * Better facilities lead to faster player development.
 */
class Training : public Facilities
{
public:
    Training();
    ~Training();

    /**
     * Get the current rate of player improvement
     * @return Improvement rate as a float
     */
    float getRateOfImprovement() const;

    /**
     * Set the rate of player improvement
     * @param rate New improvement rate
     */

    void setRateOfImprovement(float rate);

     /**
     * Check if training facilities are upgraded
     * Overrides base class pure virtual function
     * @return true if upgraded, false otherwise
     */

    bool upgraded() override;

protected:
private:
    float rateOfImprovement; // Rate at which players improve through training

};

/**
 * Tactical Class
 *
 * Represents the club's tactical facilities.
 * Affects the team's tactical knowledge and strategic abilities.
 * Better facilities improve team coordination and tactical execution.
 */


class Tactical : public Facilities
{
public:
    Tactical();
    ~Tactical();

    /**
     * Get the current level of tactical knowledge
     * @return Tactical knowledge as a float
     */


    float getTacticalKnowledge() const;

    /**
     * Set the level of tactical knowledge
     * @param knowledge New tactical knowledge level
     */


    void setTacticalKnowledge(float knowledge);

    /**
     * Check if tactical facilities are upgraded
     * Overrides base class pure virtual function
     * @return true if upgraded, false otherwise
     */


    bool upgraded() override;

protected:
private:
    float tacticalKnowledge;
};
/**
 * Player Class
 *
 * Base class representing a player in the club.
 * Manages player information, position, and attributes.
 * Provides basic functionality for training and playing matches.
 */

class Player
{
public:
    Player();
    Player(const std::string & playerName);
    virtual ~Player();


    /**
     * Get the player's name
     * @return Player name as a string
     */


    std::string getName() const;

    /**
     * Set the player's name
     * @param playerName The new player name
     */

    void setName(const std::string & playerName);

    /**
     * Get the player's current position
     * @return Pointer to PlayerPosition object
     */

    PlayerPosition* getPosition() const;

    /**
     * Set the player's position
     * @param pos Pointer to new PlayerPosition
     */

    void setPosition(PlayerPosition* pos);

     /**
     * Get the player's attributes
     * @return Pointer to PlayerAttributes object
     */
    PlayerAttributes* getAttributes() const;

    /**
     * Set the player's attributes
     * @param attr Pointer to new PlayerAttributes
     */
    void setAttributes(PlayerAttributes* attr);

    /**
     * Train the player to improve attributes
     * Virtual function that can be overridden by derived classes
     */

    virtual void train();

    /**
     * Have the player participate in a match
     * Virtual function that can be overridden by derived classes
     */

    virtual void playMatch();

    /**
     * Display all player information to console
     */

    void displayPlayerInfo() const;

protected:
    std::string name;
    PlayerPosition* position;
    PlayerAttributes* attributes;
private:
};

/**
 * Captain Class
 *
 * Represents a team captain with special abilities.
 * Extends Player class with additional leadership functions.
 * Captains can change tactics and have enhanced training benefits.
 */

class Captain : public Player
{
public:
    Captain();
    Captain(const std::string& captainName);
    ~Captain();

    /**
     * Get the captain's preferred field position
     * @return Field position as a string
     */

    std::string getField() const;

    /**
     * Check if captain has permission to change tactics
     * @return true if can change tactics, false otherwise
     */

    bool getCanChangeTactics() const;
    /**
     * Set the captain's preferred field position
     * @param fieldType The new field position
     */


    void setField(const std::string& fieldType);

    /**
     * Set the captain's preferred field position
     * @param fieldType The new field position
     */

    void setCanChangeTactics(bool tactics);

    /**
     * Change team tactics during a match
     * Captain-specific ability
     */

    void changeTactics();

    /**
     * Train the captain
     * Overrides base Player class training with captain-specific training
     */

    void train() override;

     /**
     * Display captain information
     * Shows both player info and captain-specific details
     */

    void displayPlayerInfo() const;


protected:
private:

    std::string field; // Captain's preferred field position/role
    bool canChangeTactics; // Whether captain has permission to change
};

/**
 * PlayerPosition Class
 *
 * Represents a position on the football field.
 * Tracks position name and availability.
 * Used to manage team formation and player assignments.
 */

class PlayerPosition
{
public:
    PlayerPosition();
    ~PlayerPosition();

    /**
     * Get the name of this position
     * @return Position name as a string (e.g., "Striker", "Defender")
     */

    std::string getPositionName() const;

    /**
     * Set the name of this position
     * @param name The new position name
     */

    void setPositionName(const std::string& name);

    /**
     * Check if this position is vacant
     * @return true if position is vacant, false if occupied
     */
    bool isVacant() const;

    /**
     * Set the vacancy status of this position
     * @param vacant New vacancy status
     */

    void setVacant(bool vacant);

     /**
     * Assign a player to this position
     * Marks position as occupied
     */

    void assignPlayer();

    /**
     * Clear this position
     * Removes any assigned player and marks as vacant
     */

    void clearPosition();


protected:

private:
    std::string positionName; // Name of the position (e.g., "Goalkeeper", "Midfielder")

    bool vacant; // Whether the position is currently vacant

};

/**
 * PlayerAttributes Class
 *
 * Manages all skill attributes for a player.
 * Tracks individual stats (pace, passing, shooting, etc.)
 * Calculates and maintains overall rating.
 */

class PlayerAttributes
{
public:

    PlayerAttributes();
    ~PlayerAttributes();

    // Getter methods for all attributes

    /**
     * Get the player's field/specialization
     * @return Field type as a string
     */

    std::string getField() const;

    /**
     * Get the player's attributes
     * @return value (typically 0-100)
     */

    int getPace() const;
    int getPassing() const;
    int getDefending() const;
    int getDribbling() const;
    int getShooting() const;
    int getPhysical() const;
    int getOverall() const;


    // Setter methods for all attributes

    /**
     * Set the player's field/specialization
     * @param fieldType The new field type
     */

    void setField(const std::string& fieldType);

    /**
     * Set the player's attributes
     * @param value New attribute value
     */

    void setPace(int value);
    void setDefending(int value);
    void setDribbling(int value);
    void setShooting(int value);
    void setPhysical(int value);
    void setPassing(int value);

    /**
     * Calculate the overall rating
     * Computes overall based on weighted average of all attributes
     * Updates the overall member variable
     */


    void calculateOverall();

    /**
     * Improve a specific attribute by a given amount
     * @param attributeName Name of attribute to improve (e.g., "pace", "shooting")
     * @param amount Amount to increase the attribute by
     */


    void improveAttributes(const std::string& attributeName, int amount);

protected:

private:

    std::string field; // Player's field position or specialization

    int pace; // Speed and acceleration (0-100)

    int defending; // Defensive ability and positioning (0-100)

    int dribbling; // Ball control and dribbling skill (0-100)

    int shooting; // Shooting accuracy and power (0-100)

    int physical; // Strength, stamina, and physicality (0-100)

    int passing; // Passing accuracy and vision (0-100)

    int overall; // Overall rating calculated from all attributes


};


#endif // PROCLUBSSEASON_H
