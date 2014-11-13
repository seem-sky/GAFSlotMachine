#include "SlotBar.h"

USING_NS_GAF;

SlotBar* SlotBar::create(GAFObject* mainObject)
{
    SlotBar* ret = new SlotBar();
    if (ret && ret->init(mainObject))
    {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_RELEASE(ret);
    return nullptr;
}

SlotBar::SlotBar()
{
}

bool SlotBar::init(GAFObject* mainObject)
{
    if (mainObject == nullptr)
        return false;

    m_bar = mainObject;
    
    for (int i = 0; i < 3; i++)
    {
        std::stringstream ss;
        ss << "fruit" << (i + 1);
        m_slots[i] = mainObject->getObjectByName(ss.str());

        if (m_slots[i] == nullptr)
            return false;
    }

    return true;
}

GAFObject* SlotBar::getBar()
{
    return m_bar;
}