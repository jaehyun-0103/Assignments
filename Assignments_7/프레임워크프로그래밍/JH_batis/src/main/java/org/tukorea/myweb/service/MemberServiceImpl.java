package org.tukorea.myweb.service;

import java.util.List;

import org.tukorea.myweb.domain.StudentVO;
import org.tukorea.myweb.persistence.MemberDAO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class MemberServiceImpl implements MemberService {

	@Autowired
	private MemberDAO memberDAO;

	public StudentVO readMember(String id) throws Exception {
		return memberDAO.read(id);
	}

	public List<StudentVO> readMemberList() throws Exception {
		return memberDAO.readList();
	}

	public void addMember(StudentVO student) throws Exception {
		memberDAO.add(student);
	}

	public void deleteMember(String id) throws Exception {
		memberDAO.delete(id);
	}

	public void updateMember(StudentVO student) throws Exception {
		memberDAO.update(student);
	}

}
