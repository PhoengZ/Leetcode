select w2.id
from weather w1
    join weather w2 on w1.recordDate = w2.recordDate -1
where
    w2.temperature > w1.temperature