// The Dictionary abstract class.
template <class Key, class Elem, class KEComp, class EEComp>
class Dictionary {
public:
    virtual void clear() = 0;
    virtual bool insert(const Elem&) = 0;
    virtual bool remove(const Key&, Elem&) = 0;
    virtual bool removeAny(Elem&) = 0;
    virtual bool find(const Key&, Elem&) const = 0;
    virtual int size() = 0;
};