delete from person p1 using person p2
where
    p1.id > p2.id
    and p1.email = p2.email