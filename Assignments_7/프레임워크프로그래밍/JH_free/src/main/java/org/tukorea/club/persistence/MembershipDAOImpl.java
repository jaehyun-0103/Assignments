package org.tukorea.club.persistence;

import org.apache.ibatis.session.SqlSession;
import org.tukorea.club.domain.MembershipVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

@Repository
public class MembershipDAOImpl implements MembershipDAO {

	@Autowired
	private SqlSession sqlSession;

	private static final String namespace = "MembershipMapper";

	public void add(MembershipVO vo) throws Exception {
		sqlSession.insert(namespace + ".insertMembership", vo);
	}

	public void delete(MembershipVO vo) throws Exception {
		sqlSession.insert(namespace + ".deleteMembership", vo);
	}
}