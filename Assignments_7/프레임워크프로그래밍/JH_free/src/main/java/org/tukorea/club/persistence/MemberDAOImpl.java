package org.tukorea.club.persistence;

import org.apache.ibatis.session.SqlSession;
import org.tukorea.club.domain.MemberVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

@Repository
public class MemberDAOImpl implements MemberDAO {

	@Autowired
	private SqlSession sqlSession;

	private static final String namespace = "MemberMapper";
	
	public void join(MemberVO vo) throws Exception {
		sqlSession.insert(namespace + ".insertMember", vo);
	}

	public Integer login(MemberVO vo) throws Exception {
		return sqlSession.selectOne(namespace + ".selectMember", vo);
	}

	public MemberVO read(int id) throws Exception {
		MemberVO vo = sqlSession.selectOne(namespace + ".selectMemberById", id);
		return vo;
	}

	public void update(MemberVO member) throws Exception {
		if (member.getPassword() != null) {
			sqlSession.update(namespace + ".updateMember1", member);
		} else {
			sqlSession.update(namespace + ".updateMember2", member);

		}
	}

	public void delete(int id) throws Exception {
		sqlSession.delete(namespace + ".deleteMember", id);
	}
}
