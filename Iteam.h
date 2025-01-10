#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>
#include <algorithm> // std::min 사용을 위해 포함

using namespace std; // std 네임스페이스 사용

// 추상 기본 클래스: Item
class Item {
protected:
    string name; // 아이템의 이름

public:
    // 생성자와 소멸자
    Item(const string& itemName);
    virtual ~Item();

    // 아이템 이름 반환
    string getName() const;

    // 순수 가상 함수: 아이템의 효과를 문자열로 반환
    virtual string getEffect() const = 0;
};

// 체력 포션 클래스 - Item 상속
class HealthPotion : public Item {
private:
    int healthRestore; // 회복할 체력의 양

public:
    // 생성자
    HealthPotion(int restoreAmount);

    // 회복량 반환
    int getHealthRestore() const;

    // 아이템 효과 설명 반환
    string getEffect() const override;
};

// 공격력 증가 클래스 - Item 상속
class AttackBoost : public Item {
private:
    int attackIncrease; // 증가할 공격력의 양

public:
    // 생성자
    AttackBoost(int increaseAmount);

    // 공격력 증가량 반환
    int getAttackIncrease() const;

    // 아이템 효과 설명 반환
    string getEffect() const override;

    // 공격력 증가 효과 적용
    void applyEffect(int& temporaryAttack);

    // 공격력 증가 효과 제거 (사용전 공격력으로 복구)
    void removeEffect(int& temporaryAttack, int originalAttack);
};

// 마나 포션 클래스 - Item 상속
class ManaPotion : public Item {
private:
    int manaRestore; // 회복할 마나의 양

public:
    // 생성자
    ManaPotion(int restoreAmount);

    // 회복할 마나 양 반환
    int getManaRestore() const;

    // 아이템 효과 설명 반환
    string getEffect() const override;
};

#endif // ITEM_H
