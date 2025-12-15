select Date as Day, round((num_cancle::numeric / total),2) as "Cancellation Rate" from (
	select t.request_at as Date, sum(case when t.status != 'completed' then 1 else 0 end) as num_cancle , count(*) as total 
	from users u join trips t on u.users_id = t.client_id join users d on d.users_id = t.driver_id
	where t.request_at >= '2013-10-01' and request_at <= '2013-10-03' and u.banned = 'No' and d.banned = 'No'
	group by t.request_at
) temp_table